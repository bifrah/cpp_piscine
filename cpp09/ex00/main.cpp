#include "include.hpp"

// Fonction pour convertir une date en nombre de jours depuis le 1er janvier 1970
time_t date_to_days(const std::string& date_str)
{
	std::tm date = {};
	std::istringstream date_iss(date_str);
	int year, month, day;
	if (std::sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		throw std::invalid_argument("invalid date format");
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;
	date.tm_hour = 12;
	return std::mktime(&date) / (60 * 60 * 24);
}

bool is_valid_date(const std::string& date_str)
{
	// Vérification des positions des tirets
	if (date_str[4] != '-' || date_str[7] != '-')
		return false;

	// Vérification que chaque partie de la date est un entier valide
	int year, month, day;
	if (std::sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return false;
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	// Si toutes les vérifications sont passées, la date est valide
	return true;
}

bool is_valid_line_format(const std::string& line) {
	// Vérification du format de la ligne
	if (line.empty() || (line.find('|') == std::string::npos)) {
		std::cerr << "Error: line: invalid format" << std::endl;
		return false;
	}

	// Extraction de la date et de la valeur de la ligne
	std::istringstream iss(line);
	std::string date_str, value_str;
	std::getline(iss, date_str, '|');
	std::getline(iss, value_str);

	// Vérification de la validité de la date
	if (!is_valid_date(date_str)) {
		std::cerr << "Error: date: invalid format" << std::endl;
		return false;
	}

	// Vérification de la validité de la valeur
	if (value_str.empty())
	{
		std::cerr << "Error: value: empty" << std::endl;
		return (false);
	}
	float value = std::atof(value_str.c_str());
	if (value < 0 || value > 1000) {
		std::cerr << "Error: value: out of range" << std::endl;
		return false;
	}
	return true;
}

// Fonction qui ajoute les données d'un fichier .csv dans une map
void add_csv_data_to_map(std::map<time_t, float>& data_map, std::ifstream& csv_file)
{
	std::string line;
	int line_count = 0;
	while (std::getline(csv_file, line))
	{
		// Ignore la première ligne du fichier .csv "date,exchange_rate"
		if (line_count == 0)
		{
			line_count++;
			continue;
		}
		std::string date_str = line.substr(0, line.find(','));
		std::string value_str = line.substr(line.find(',') + 1);
		float value;
		std::istringstream(value_str) >> value;
		if (value_str.empty() || std::isnan(value))
			continue;
		time_t date = date_to_days(date_str);
		data_map[date] = value;
	}
}

void process_file(std::ifstream& infile, std::map<time_t, float>& bitcoin_data)
{
	std::string line;
	while (std::getline(infile, line))
	{
		// Vérification du format de la ligne
		if (!is_valid_line_format(line))
			continue;

		// Extraction de la date et de la valeur de la ligne
		std::istringstream iss(line);
		std::string date_str, value_str;
		std::getline(iss, date_str, '|');
		std::getline(iss, value_str);
		float value;
		std::istringstream(value_str) >> value;
		time_t date = date_to_days(date_str);

		// Recherche de la date dans la map
		std::map<time_t, float>::iterator it = bitcoin_data.find(date);
		if (it == bitcoin_data.end())
		{
			// La date n'existe pas dans la map, il faut utiliser la date la plus proche
			std::map<time_t, float>::iterator lower = bitcoin_data.lower_bound(date);
			if (lower == bitcoin_data.begin())
			{
				// Date inférieure à toutes les dates dans la map
				std::cout << date_str << " => " << value << " = 0" << std::endl;
			}
			else if (lower == bitcoin_data.end())
			{
				// Date supérieure à toutes les dates dans la map
				std::cout << date_str << " => " << value << " = " << bitcoin_data.rbegin()->second * value << std::endl;
			}
			else
			{
				// Date entre deux dates dans la map
				float val_upper = (--lower)->second;
				std::cout << date_str << " => " << value << " = " << val_upper * value << std::endl;
			}
		}
		else
		{
			// La date existe dans la map
			std::cout << date_str << " => " << value << " = " << it->second * value << std::endl;
		}
	}
}

int main(int argc, char** argv)
{
	// Vérification des arguments de la ligne de commande
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	// Ouverture du fichier d'entrée
	std::ifstream infile(argv[1]);
	if (!infile)
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return 1;
	}
	// Ouverture du fichier des données data.csv
	std::ifstream bitcoin_file("data.csv");
	if (!bitcoin_file)
	{
		std::cerr << "Error: could not open Bitcoin data file." << std::endl;
		return 1;
	}

	// Ajout des données data.csv dans une map
	std::map<time_t, float> bitcoin_data;
	add_csv_data_to_map(bitcoin_data, bitcoin_file);
	bitcoin_file.close();
	// Parcours du fichier d'entrée et affichage des résultats
	process_file(infile, bitcoin_data);
	return (0);
}

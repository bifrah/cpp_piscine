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

	// Ouverture du fichier des données Bitcoin
	std::ifstream bitcoin_file("data.csv");
	if (!bitcoin_file)
	{
		std::cerr << "Error: could not open Bitcoin data file." << std::endl;
		return 1;
	}

	// Ajout des données Bitcoin dans une map
	std::map<time_t, float> bitcoin_data;
	std::string line;
	while (std::getline(bitcoin_file, line))
	{
		std::string date_str = line.substr(0, line.find(','));
		std::string value_str = line.substr(line.find(',') + 1);
		float value;
		std::istringstream(value_str) >> value;
		if (value_str.empty() || std::isnan(value))
			continue;
		time_t date = date_to_days(date_str);
		bitcoin_data[date] = value;
	}

	// Parcours du fichier d'entrée et affichage des résultats
	while (std::getline(infile, line))
	{
		// Extraction de la date et de la valeur de la ligne
		std::istringstream iss(line);
		std::string date_str, value_str;
		std::getline(iss, date_str, '|');
		std::getline(iss, value_str);
		float value;
		std::istringstream(value_str) >> value;
		if (value_str.empty() || std::isnan(value))
			continue;

		// Chercher la date la plus proche dans la map
		time_t target_date = date_to_days(date_str);
		time_t closest_date = 0;
			float closest_distance = std::numeric_limits<float>::max();
			for (std::map<time_t, float>::iterator it = bitcoin_data.begin(); it != bitcoin_data.end(); ++it)
			{
				float distance = std::abs(difftime(it->first, target_date));
				if (distance < closest_distance)
				{
					closest_distance = distance;
					closest_date = it->first;
				}
			}

		// Récupérer la valeur associée à la date la plus proche
		float closest_value = bitcoin_data[closest_date];

		// Affichage des résultats : valeur de la date la plus proche * valeur du fichier d'entree.
		std::cout << date_str << " => " << value << " = " << closest_value * value << std::endl;
	}
	return (0);
}

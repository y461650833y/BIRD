#include "create_library_header.h"

int ReadParam(char *infile, int *parameter, char **filename)
{
	FILE * p_in;
	char par_name[255];
	int temp_int;
	char temp_char[255];
	p_in = fopen(infile, "r");
	if (p_in != NULL)
	{
		std::cout << "Reading " << infile << "..." << std::endl;
		while (!feof(p_in) && fscanf(p_in, "%s", par_name) == 1)
		{
			if (strcmp(par_name, "NumLoci") == 0)
			{
				fscanf(p_in, "%d", &temp_int);
				parameter[0] = temp_int;
				std::cout << "NumLoci=" << temp_int << std::endl;
			}
			else if (strcmp(par_name, "NumGene") == 0)
			{
				fscanf(p_in, "%d", &temp_int);
				parameter[1] = temp_int;
				std::cout << "NumGene=" << temp_int << std::endl;
			}
			else if (strcmp(par_name, "NumCluster") == 0)
			{
				fscanf(p_in, "%d", &temp_int);
				parameter[2] = temp_int;
				std::cout << "NumCluster=" << temp_int << std::endl;
			}
			else if (strcmp(par_name, "NumBin") == 0)
			{
				fscanf(p_in, "%d", &temp_int);
				parameter[3] = temp_int;
				std::cout << "NumBin=" << temp_int << std::endl;
			}
			else if (strcmp(par_name, "NumVar") == 0)
			{
				fscanf(p_in, "%d", &temp_int);
				parameter[4] = temp_int;
				std::cout << "NumVar=" << temp_int << std::endl;
			}
			else if (strcmp(par_name, "GeneQuantile") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[0], temp_char);
			}
			else if (strcmp(par_name, "GeneMean") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[1], temp_char);
			}
			else if (strcmp(par_name, "GeneSD") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[2], temp_char);
			}
			else if (strcmp(par_name, "ClusterIndex") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[3], temp_char);
			}
			else if (strcmp(par_name, "DNaseMean") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[4], temp_char);
			}
			else if (strcmp(par_name, "DNaseSD") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[5], temp_char);
			}
			else if (strcmp(par_name, "RegressionCoef") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[6], temp_char);
			}
			else if (strcmp(par_name, "RegressionPredictor") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[7], temp_char);
			}
			else if (strcmp(par_name, "GenomicLoci") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[8], temp_char);
			}
			else if (strcmp(par_name, "GeneName") == 0)
			{
				fscanf(p_in, "%s", &temp_char);
				strcpy(filename[9], temp_char);
			}
			else
			{
				break;
			}
		}

	}
	else
	{
		std::cout << "Error! File "<<infile<< " not found!" << std::endl;
		return 1;
	}

	return 0;
}

int ReadVector_d(char *infile, double *data)
{
	FILE *p_in;
	int i = 0;
	double temp_double;
	p_in = fopen(infile, "r");
	if (p_in != NULL)
	{
		std::cout << "Reading " << infile << "..." << std::endl;
		while (!feof(p_in) && fscanf(p_in, "%lf", &temp_double) == 1)
		{
			data[i] = temp_double;
			i++;
		}
		fclose(p_in);
	}
	else
	{
		std::cout << "Error! File "<<infile<<" not found!" << std::endl;
		return 1;
	}

	return 0;
}



int ReadVector_i(char *infile, int *data)
{
	FILE *p_in;
	int i = 0;
	int temp_int;
	p_in = fopen(infile, "r");
	if (p_in != NULL)
	{
		std::cout << "Reading " << infile << "..." << std::endl;
		while (!feof(p_in) && fscanf(p_in, "%d", &temp_int) == 1)
		{
			data[i] = temp_int;
			i++;
		}
		fclose(p_in);
	}
	else
	{
		std::cout << "Error! File " << infile << " not found!" << std::endl;
		return 1;
	}

	return 0;
}

int ReadMatrix_d(char *file, double **data)
{
	std::ifstream infile(file);
	std::string line_temp;
	std::string line_token;
	int m, k;
	m = 0;
	if (infile.is_open())
	{
		std::cout << "Reading " << file << "..." << std::endl;
		while (!infile.eof())
		{
			std::getline(infile, line_temp);
			if (line_temp.empty()){ break; }
			std::stringstream each_line(line_temp);
			k = 0;
			while (std::getline(each_line, line_token, '\t'))
			{
				data[k][m] = atof(line_token.c_str());
				k++;
			}
			m++;
		}

		infile.close();
	}
	else
	{
		std::cout << "Error! File " << file << " not found!" << std::endl;
		return 1;
	}

	return 0;

}

int ReadMatrix_i(char *file, int **data)
{
	std::ifstream infile(file);
	std::string line_temp;
	std::string line_token;
	int m, k;
	m = 0;
	if (infile.is_open())
	{
		std::cout << "Reading " << file << "..." << std::endl;
		while (!infile.eof())
		{
			std::getline(infile, line_temp);
			if (line_temp.empty()){ break; }
			std::stringstream each_line(line_temp);
			k = 0;
			while (std::getline(each_line, line_token, '\t'))
			{
				data[k][m] = atoi(line_token.c_str());
				k++;
			}
			m++;
		}

		infile.close();
	}
	else
	{
		std::cout << "Error! File " << file << " not found!" << std::endl;
		return 1;
	}

	return 0;

}

int ReadName(char *file, char **data)
{
	std::ifstream infile(file);
	std::string line_temp;
	int m = 0;
	if (infile.is_open())
	{
		std::cout << "Reading " << file << "..." << std::endl;
		while (!infile.eof())
		{
			std::getline(infile, line_temp);
			if (line_temp.empty()){ break; }
			strncpy(data[m], line_temp.c_str(), 30);
			m++;
		}
		infile.close();
	}
	else
	{
		std::cout << "Error! File " << file << " not found!" << std::endl;
		return 1;
	}

	return 0;
}
/*********************************************************************/
/*                       INCLUDES AND DEFINES                        */
/*********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <string>
#include <omp.h>

#include "Helper.hpp"
#include "AES.hpp"
#include "Mode.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	// Define Variables
	unsigned int iv_length = 12;

	string file_path_messages = "C:/Users/Jan/Dropbox/_Programmieren/Kryptographie/AES/text.txt";

	vector<ByteArray> decrypted_solution;
	vector<ByteArray> encrypted_solution;

	// Load data from files
	ByteArray key = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	ByteArray IV = random_byte_array(iv_length);
	vector<ByteArray> messages = read_datafile(file_path_messages);

	encrypted_solution = counter_mode(messages, key, IV);



	decrypted_solution = counter_mode_inverse(encrypted_solution, key, IV);

	cout << endl << "Legit solution: " << check_vector_of_byte_arrays(decrypted_solution, messages) << endl;

	getchar();
}

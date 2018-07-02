#include <iostream>
#include <string>

using namespace std;

void printSubString(char* arraySubString[], int digit){
	int k = 0;
	for(int i = 0; i < digit; i++){
		k = 0;
		while(arraySubString[i][k] != '\0'){
			if(isspace(arraySubString[i][k])) break;
			cout << arraySubString[i][k];
			k++;
		}
		cout << " ";
	}
}


void swap(char* arraySubString[], int i){
	char& aux = *arraySubString[i + 1];
	arraySubString[i + 1] = arraySubString[i];
	arraySubString[i] = &aux;
}

void sortSubString(char* arraySubString[], int digit){
	for(int j = 0; j < digit; j++){
		for(int i = 0; i < digit; i++){
			if(tolower(arraySubString[i][0]) > tolower(arraySubString[i + 1][0])){
				swap(arraySubString, i);
			}
			else if(tolower(arraySubString[i][0]) == tolower(arraySubString[i + 1][0])){
				int l = 1;
				while(tolower(arraySubString[i][l]) == tolower(arraySubString[i + 1][l])){
					l++;
				}
				if(tolower(arraySubString[i][l]) > tolower(arraySubString[i + 1][l])){
					swap(arraySubString, i);
				}
			}
		}			
	}
}

int main(){
	int digit;
	string str;
	string::size_type posStart = 0;
	
	cout << "Type a string in format DIGIT_(STR)*DIGIT:" << endl;
	getline(cin, str);
	//get first digit and convert to int
	digit = stoi(str);
	
	if(0 <= digit and digit <= 1000){
		//create an array of pointers to substrings
		char* arraySubString[digit];
		for(int i = 0; i < digit; i++){
			posStart = str.find(" ",posStart);
			++posStart;
			arraySubString[i] = &str[posStart];
		}
		sortSubString(arraySubString, digit);
		printSubString(arraySubString, digit);
	}	
return 0;
}


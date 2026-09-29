#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
    ifstream ist("human_protein_interaction.txt");

    if (!ist) {
        cerr << "このファイルは開けません" << endl;
        exit(1);
    }
    string line;
    string protein1, protein2;
    map<string, int> protein_count;
    string most_connected_protein;
    int max_count = 0;
    while(getline(ist, line)) {
        int space=line.find(' ');
        protein1=line.substr(0, space);
        protein2=line.substr(space+1);
        protein_count[protein1]++;
        protein_count[protein2]++;
        if(protein_count[protein1] > max_count) {
            max_count = protein_count[protein1];
            most_connected_protein = protein1;
        }
        if(protein_count[protein2] > max_count) {
            max_count = protein_count[protein2];
            most_connected_protein = protein2;
        }
    }
    cout << "最も接続されているタンパク質: " << most_connected_protein << " (接続数: " << max_count << ")" << endl;
    
    return 0;
}





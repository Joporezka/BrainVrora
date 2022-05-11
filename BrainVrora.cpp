#include "BrainVrora.h"
using namespace std;


/*
 * Словарь команд:
 *  > - "Avrora!"
 *  < - "Avrora?"
 *  + - "AVRORA"
 *  - - "avrora"
 *  . - "AvrorA"
 *  , - "Avrora..."
 *  [ - "AVRora"
 *  ] - "avrORA"
 *
 */




string convert_bf_to_brainvrora(string bf_file, string brainvrora_file) {
    map<char, string> commands;
    commands['>'] = "Avrora! ";
    commands['<'] = "Avrora? ";
    commands['+'] = "AVRORA ";
    commands['-'] = "avrora ";
    commands['.'] = "AvrorA ";
    commands[','] = "Avrora... ";
    commands['['] = "AVRora ";
    commands[']'] = "avrORA ";

    ifstream infile(bf_file);
    ofstream outfile(brainvrora_file);
    char c;
    while (infile>>c) {
        outfile<<commands[c];
    }
    infile.close();
    outfile.close();
    outfile<<"puk";
    return "Success cast to brainvrora.txt\n\n\n";
}

string interpetBrainVrora( string fileName) {

    ifstream algorthimFile;
    algorthimFile.open(fileName);

    if (!algorthimFile.is_open()) {
        return "File Error";
    }

    vector<string> acc;
    string buffer;

    while (algorthimFile) {
        algorthimFile>> buffer;
        acc.push_back(buffer);
    }
    algorthimFile.close();
    unsigned int j = 0;
    int brc = 0;
    for (int i = 0; i < acc.size(); ++i) {
        if (acc[i] == "Avrora!")
            j++;
        if (acc[i] == "Avrora?")
            j--;
        if (acc[i] == "AVRORA")
            cpu[j]++;
        if (acc[i] == "avrora")
            cpu[j]--;
        if (acc[i] == "AvrorA")
            cout << cpu[j];
        if (acc[i] == "Avrora...")
            cin >> cpu[j];
        if (acc[i] == "AVRora") {
            if (!cpu[j]) {
                ++brc;
                while (brc) {
                    ++i;
                    if (acc[i] == "AVRora")
                        ++brc;
                    if (acc[i] == "avrORA")
                        --brc;
                }
            } else
                continue;
        } else if (acc[i] == "avrORA") {
            if (!cpu[j])
                continue;
            else {
                if (acc[i] == "avrORA")
                    brc++;
                while (brc) {
                    --i;
                    if (acc[i] == "AVRora")
                        brc--;
                    if (acc[i] == "avrORA")
                        brc++;
                }
                --i;
            }
        }
    }

    return "Success! Enjoy your life!";
}

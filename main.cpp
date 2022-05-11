#include "BrainVrora.h"

static string input_path =  "D:\\Clion\\BrainVrora\\input.txt";
static string bv_path =  "D:\\Clion\\BrainVrora\\brainvrora.txt";


int main() {
    cout<<convert_bf_to_brainvrora(input_path, bv_path);
    cout<<interpetBrainVrora(bv_path);
    return 0;
}

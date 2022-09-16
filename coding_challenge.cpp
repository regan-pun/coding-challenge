#include <iostream>

using namespace std;

// function declaration
string OldPhonePad(string input);

int main() 
{
    // decoding the input and outputting correct letters 
    cout<<OldPhonePad("8 88777444666*664#");
    
    return 0;
}

string OldPhonePad(string input)
{
    string parse, output;
    int temp, count;
    for(int i = 0; i  <input.length(); i++)
    {
        // remove previous character from output
        if(input[i] == '*')
        {
            // check if output has characters
            if(output.length() > 0)
            {
                output.pop_back();
            }            
        }
        
        // check for end of character sign 
        else if(input[i] == '#')
        {
            break;
        }

        // check if input is a digit above 1
        else if(isdigit(input[i]) && input[i]>1)
        {
            // copy the index counter
            count = i;
            // check if first and second characters matches
            if(input[i] == input[i+1])
            {
                // check if second and third characters matches
                if(input[i+1] == input[i+2])
                {
                    // check if third and fourth characters matches
                    if(input[i+2] == input[i+3])
                    {
                        // copy the character and increment the index counter
                        parse += input[i+3];
                        count++;
                    }                    
                    parse += input[i+2];
                    count++;
                }
                parse += input[i+1];
                count++;            
            }
            parse += input[i];  
            i = count;

            // convert string into integer
            temp = stoi(parse);
            parse.clear();

            // find the alphabet that represents the integer
            switch(temp)
            {
                case 2:
                    output.push_back('A');
                    break;
                case 22:
                    output.push_back('B');
                    break;
                case 222:
                    output.push_back('C');
                    break;
                case 3:
                    output.push_back('D');
                    break;
                case 33:
                    output.push_back('E');
                    break;
                case 333:
                    output.push_back('F');
                    break;
                case 4:
                    output.push_back('G');
                    break;
                case 44:
                    output.push_back('H');
                    break;
                case 444:
                    output.push_back('I');
                    break;
                case 5:
                    output.push_back('J');
                    break;
                case 55:
                    output.push_back('K');
                    break;
                case 555:                    
                    output.push_back('L');
                    break;
                case 6:
                    output.push_back('M');
                    break;
                case 66:
                    output.push_back('N');
                    break;
                case 666:
                    output.push_back('O');
                    break;
                case 7:
                    output.push_back('P');
                    break;
                case 77:
                    output.push_back('Q');
                    break;
                case 777:
                    output.push_back('R');
                    break;
                case 7777:
                    output.push_back('S');
                    break;
                case 8:
                    output.push_back('T');
                    break;
                case 88:
                    output.push_back('U');
                    break;
                case 888:
                    output.push_back('V');
                    break;
                case 9:
                    output.push_back('W');
                    break;
                case 99:
                    output.push_back('X');
                    break;
                case 999:
                    output.push_back('Y');
                    break;
                case 9999:
                    output.push_back('Z');
                    break;
                default:
                break;
            }
        }
        
        // ignore if the input is space or other symbols.
        else
        {
            continue;
        }
    }

    return output;
}
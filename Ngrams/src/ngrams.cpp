// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"
#include "map.h"
#include "stack.h"
#include "queue.h"
#include "random.h"

using namespace std;

void PutinArgs(int N,int length);
void ScanDocument(string & doc,Vector<string> & lines);
void GenerateMap(Map<Vector<string>,Vector<string>> & map,Vector<string> & lines,int N);

int main() {
    // TODO: Finish the program!

    setConsoleSize(750, 450);
    setConsoleFont("Courier New-16");
    setConsoleEcho(true);
while(true){

    string doc;
    int N,length;//N:Ngrams length: how many words u want to put out.
    cout << "Value of N?";
    cin >> N;
    cout << "Length of the words?";
    cin >> length;

    /* Scan the Document and put every word in lines Vector */
    Map<Vector<string>,Vector<string>> map;
    Vector<string> lines;
    ScanDocument(doc,lines);

    GenerateMap(map,lines,N);


    Stack<string> output;
    Stack<string> temp;
    Vector<string> randomKey;

    int randInt = randomInteger(1,map.keys().size()-1);
    randomKey = map.keys()[randInt];
    for( int i =0;i<N;i++){
        output.push(randomKey[i]);
        }
    while(length>0){
        Vector<string> tempkey,nextkey;
        Vector<string> randomValue = map[randomKey];
        randInt = randomInteger(0,randomValue.size()-1);
        string word = randomValue[randInt];
        output.push(word);
        temp = output;
        for(int i=0;i<N;i++){
            tempkey.add(temp.pop());
            }
        for(int i=N-1;i>=0;i--){
            nextkey.add(tempkey[i]); //反向
            }
        randomKey = nextkey;
        length --;
        }
        
    cout<<"......";    
    while(!output.isEmpty()){
        cout<<output.pop();
        cout<<" ";
    }
    cout<<"......\n\n\n\n"<<endl;

}
    
    return 0;
}


void PutinArgs(int N,int length)
{
    cout << "Value of N?";
    cin >> N;
    cout << "Length of the words?";
    cin >> length;
}

void ScanDocument(string & doc,Vector<string> & lines)
{
    ifstream stream;
    {
    while(true){
        cout << "Input file name:";
        cin >> doc;
        stream.open(doc.c_str());
        if(stream.fail()){
        cout<<"Can not find that document.Try Again"<<endl;
        continue;
        }
        else{
            break;
        }
    }
    while(true){
          string text;
          stream >> text;
          if(stream.fail()){
               break;
          }
          else{
          lines.add(text);
          }
      }
    }
    stream.close();
}


void GenerateMap(Map<Vector<string>,Vector<string>> & map,Vector<string> & lines,int N)
{
    int i=0,j=0,end;


    for(i=0;i<lines.size();i++){    //i: the words that we have used.
        Vector<string> key;                            //N: the words that we need to use
        /*Generate the key,and managed the problem when it comes to the end of the lines */
        if( i+N<lines.size() ){
            end=i+N;
            for(j=i;j<end;j++){
                key.add(lines[j]);
            }
        }

        else{
            end = (i+N)%lines.size();
            for( j=i;j<lines.size();j++){
                key.add(lines[j]);
            }

            for( j=0;j<end;j++ ){
                key.add(lines[j]);
            }
        }

        string nword;
        nword = lines.get(end); //end = i+N,so lines.get(end) enable us to get the value.
        Vector<string> value;
        if( map.containsKey(key)){
            value = map.get(key);
            value.add(nword);
            map.put(key,value);
        }
        else{
            value.add(nword);
            map.put(key,value);
        }
    }
}























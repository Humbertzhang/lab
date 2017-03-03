// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <stdio.h>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"
#include "console.h"
#include "vector.h"
#include "map.h"
#include "simpio.h"


using namespace std;

string lower(string word);
void getdic();
int valid(Vector<string> & lines,string word);


Vector<string> lines;//每行单词的队列
Vector<string> used;


int main() {
    
    printf("Welcome to CS 106B Word Ladder.\n");
    printf("Please give me two English words, and I will change the\n");
    printf( "first into the second by changing one letter at a time.\n");
    cout << "Dictionary file name?" <<endl;
    getdic();//读取字典函数
    
    string word1,word2;


    while(true){
    cout<< " "<<endl;
    cout <<"input '1' to exit"<<endl;
    cout <<"Word #1:"<<endl;
    cin  >> word1;
    cout <<"Word #2:"<<endl;
    cin  >> word2;
    word1 = lower(word1);
    word2 = lower(word2);
        if (word1.length() != word2.length()){  //判断输入是否合法
            cout <<"The length of two words must be same."<<endl;
            continue;
            }
        if (valid(lines,word1) == 0||valid(lines,word2) ==0){
            cout <<"The two words must be found in the dictionary."<<endl;
            continue;
            }
        if (word1 == word2){
            cout <<"The two words must be different."<<endl;
            continue;
            }
        if (word1 == "0"){
            cout<<"Have a nice day"<<endl;
            break;
        }
    if (valid(lines,word1)&&valid(lines,word2)){ 
        Queue<Stack<string>> queues;
        Stack<string> ladder;
        Stack<string> first;
        Stack<string> ladderend;
        first.push(word1);
        queues.enqueue(first);
        while(!queues.isEmpty()){

            ladder = queues.dequeue();
            string word = ladder.peek();
            if (word == word2){
                ladderend = ladder;
                goto output;
                }
            else{
                for(int i = 0;i < word.length();i++){
                    for(int j =0;j<26;j++){
                        string next = word;
                        next[i]='a' + j;
                        if(next == word2){
                            ladder.push(next);
                            ladderend = ladder;
                            goto output;
                            }
                        if (valid(lines,next) && !valid(used,next)){

                            Stack<string> ladder2 = ladder;
                            ladder2.push(next);
                            queues.enqueue(ladder2);
                            used.add(next);
                            }
                        }
                    }
                }
            }
            output:
            if(ladderend.isEmpty()){
                cout<<"No Word Latter from "<<word2<<" to "<<word1<<endl;
            }
            else if(!ladderend.isEmpty()){
                cout << "Ladder From "<<word2<<" back to "<<word1<< endl;
                while(!ladderend.isEmpty()){
                    cout << ladderend.pop() <<"  ";
                    }
            }

        }
    }
    return 0;
}

string lower(string word)
{
    int i;
    for (i=0;i<word.length();i++){
        word[i] = tolower(word[i]);
    }
    return word;
}

void getdic()
{
    ifstream doc;          //dic 文件名 doc文件流
    while(true){
        string dic;
        cin >> dic;
        doc.open(dic);
        if (doc.fail()){
            cout << "Can not find "<<dic<<" document."<<endl;
            cout << "Try Again."<<endl;
            }
        else{
            while(true){
                string str;
                getline(doc,str);
                if (doc.fail())
                    break;
                else 
                    lines.add(str);
                }
            break;
            }
        }    
}

int valid(Vector<string> & lines,string word)
{
    int i;
    for(i=0;i<lines.size();i++){
        if (word == lines[i])
            return 1;
       }
    return 0;
}

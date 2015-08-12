#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct dictionaryNode{
    string str;
    string disc;
    dictionaryNode* next;
};

struct headPtr{
    int noOfWords;
    dictionaryNode* list;
};

headPtr* createDictionaryStructure(int n){
    headPtr* hp=new headPtr;
    hp->noOfWords=n;
    hp->list=new dictionaryNode[26];
    for(int i=0;i<n;i++){
        hp->list[i].next=NULL;
    }
    return hp;
}

dictionaryNode* createDictionaryNode(){
    dictionaryNode* dnode=new dictionaryNode;
    dnode->next=NULL;
    return dnode;
}

void insertIntoDictionary(headPtr* hp,string str,string disc){
    dictionaryNode* tmp=&hp->list[str[0]-'a'];
    while(tmp->next){
        tmp=tmp->next;
    }
    tmp->next=createDictionaryNode();
    tmp=tmp->next;
    tmp->str=str;
    tmp->disc=disc;
}

dictionaryNode* searchIntoDictionary(headPtr* hp,string str){
    dictionaryNode* tmp=&hp->list[str[0]-'a'];
    tmp=tmp->next;
    while(tmp!=NULL && tmp->str!=str)
        tmp=tmp->next;
    if(tmp)
        return tmp;
    return NULL;
}

int main(){
    int n;
    ifstream fin;fin.open("dictionary.txt");
    //cout<<"How many strings are there in dictionary?\n";
    fin>>n;
    headPtr* hp=createDictionaryStructure(n);
    string str,disc;
    while(!fin.eof()){
        //cout<<"Enter string\n";
        getline(fin,str,' ');
        //cin.ignore(100,'\n');
        //cout<<"Enter discription of string\n";
        getline(fin,disc,'\n');
        insertIntoDictionary(hp,str,disc);
    }

    cout<<"Enter a string you want to search\n";
    cin>>str;
    dictionaryNode* tmp=searchIntoDictionary(hp,str);
    if(tmp)
        cout<<tmp->str<<" : "<<tmp->disc<<endl;
    else
        cout<<"String not found\n";
    return 0;
}

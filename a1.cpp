#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(int argc,char**argv)
{
    int count1;
    int count2;
    int Result=0;
    int operand2;
    char temp1;
    char word[10];
    char word1[30];
    char word2[30];
    char operand[10];
    int max1,min1,range,Seed,Lenght,num;
    if(argv[1]==0)
    {
        cout<<"Incorrect Number of Arguments";
        return 0;
    }
    if(strcmp(argv[1],"print")==0)
    {
        if(argv[2]==0)
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        for(count1=2; count1<argc; count1++)
        {
            cout<<argv[count1];
            if(count1!=argc-1)
                cout<<' ';
        }
    }
    else if(strcmp(argv[1],"reverse")==0)
    {
        if(argv[2]==0)
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        for(count1=argc-1; count1>=2; count1--)
        {
            cout<<argv[count1];
            if(count1!=2)
                cout<<' ';
        }
    }
    else if(strcmp(argv[1],"upper")==0)//Before print??
    {
        if(argv[2]==0)
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        for(count1=2; count1<argc; count1++)
        {
            count2=0;
            strcpy(word,argv[count1]);
            while(word[count2]!=0)
            {
                if(word[count2]<97 || word[count2]>122)
                {
                    cout<<word[count2];
                }
                else
                {
                    word[count2]-=0x20;
                    cout<<word[count2];
                }
                count2++;
            }
            cout<<' ';
        }

    }
    else if(strcmp(argv[1],"shuffle")==0)
    {
        if(argv[2]==0 || argv[3]!=0)
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        for(count1=2; count1<argc; count1++)
        {
            count2=0;
            strcpy(word,argv[count1]);
            while(word[count2]!=0 && word[count2+1]!=0)
            {
                temp1=word[count2];
                word[count2]=word[count2+1];
                word[count2+1]=temp1;
                count2+=2;
            }
            cout<<word<<' ';
        }

    }
    else if(strcmp(argv[1],"shuffleStatement")==0)
    {
        if(argv[2]==0)
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        for(count1=2; count1<(argc-1); (count1=count1+2))
        {
//            word1={0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,};
 //           strcpy(word1,argv[count1]);
 //           strcpy(word2,argv[count1+1]);
            cout<<argv[count1+1]<<' '<<argv[count1]<<' ';
        }
        if(argc%2==1)
            cout<<argv[argc-1];
    }
    else if(strcmp(argv[1],"delete")==0) //if user enter a letter??//just delete from printing??
    {
        if(argv[2]==0 || argv[3]==0)
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        char index[1];
        int index2;
        strcpy(index,argv[2]);
        index2=atoi(index);
        if(index2<1)
        {
            cout<<"Incorrect Data Type";
            return 0;
        }
        if(index2>(argc-3))
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        for(count1=3; count1<argc; count1++)
        {
            if(count1!=(index2+2))
            {
                cout<<argv[count1]<<' ';
            }

        }

    }
    else if(strcmp(argv[1],"middle")==0)//just print or store??
    {
        if(argv[2]==0)
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        if((argc)%2==0) //even
            {
                cout<<argv[argc/2]<<' '<<argv[argc/2+1];
            }
        else
            {
                cout<<argv[(argc+1)/2];
            }
    }
    else if(strcmp(argv[1],"add")==0)//what if user enter a letter???
    {
        for(count1=2; count1<argc; count1++)
        {
            if(!(argv[count1][0]=='+' || argv[count1][0]=='-' || isdigit(argv[count1][0])))
            {
                cout<<"Incorrect Data Type";
                return 0;
            }
            if((argv[count1][0]=='+' || argv[count1][0]=='-') && argv[count1][1]==0)
            {
                cout<<"Incorrect Data Type";
                return 0;
            }
            if(atoi(argv[count1])>2147483646 || atoi(argv[count1])<-2147483647)
            {
                cout<<"Incorrect Data Type";
                return 0;
            }
            count2=1;
            while(argv[count1][count2]!=0)
            {
                if(!(isdigit(argv[count1][count2])))
                {
                    cout<<"Incorrect Data Type";
                    return 0;
                }
                count2++;
            }
        }
        if(argv[2]==0)
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        Result=0;
        for(count1=2; count1<argc; count1++)
        {
            strcpy(operand,argv[count1]);
            operand2=atoi(operand);
            Result+=operand2;
        }
        cout<<Result;
    }
    else if(strcmp(argv[1],"random")==0)// what if user enter a number na2ess
    {
        if(argv[2]==0 || argv[3]==0 || argv[4]==0 || argv[5]==0 || argv[6]!=0)
        {
            cout<<"Incorrect Number of Arguments";
            return 0;
        }
        for(count1=2; count1<argc; count1++)
        {
            if(!(argv[count1][0]=='+' || isdigit(argv[count1][0])))
            {
                cout<<"Incorrect Data Type";
                return 0;
            }
            if(argv[count1][0]=='+' && argv[count1][1]==0)
            {
                cout<<"Incorrect Data Type";
                return 0;
            }
            count2=1;
            while(argv[count1][count2]!=0)
            {
                if(!(isdigit(argv[count1][count2])))
                {
                    cout<<"Incorrect Data Type";
                    return 0;
                }
                count2++;
            }
            if(atoi(argv[count1])>2147483646 || atoi(argv[count1])<-2147483647)
            {
                cout<<"Incorrect Data Type";
                return 0;
            }
        }
        Seed=atoi(argv[5]);
        min1=atoi(argv[3]);
        max1=atoi(argv[4]);
        Lenght=atoi(argv[2]);

        if(min1>=max1 || Lenght<=0)
        {
            cout<<"Incorrect Data Type";
            return 0;
        }
        range = max1-min1 + 1;
        srand(Seed);
        for(count1=0;count1<Lenght;count1++)
        {
            num=rand()%range + min1;
            cout<<num<<' ';
        }
    }
    else
    {
        cout<<"Undefined Command";
    }
    return 0;
}
//new

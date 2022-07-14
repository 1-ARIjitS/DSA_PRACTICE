#include <iostream>

using namespace std;
//method 1- using 3 pointer approach in O(n1+n2) time and O(1) space
void validstr3pointer(string s1, string s2, string s3)
{
    int n1= s1.length();
    int n2= s2.length();
    int n3= s3.length();

    if(n3!=(n1+n2))
    {
        cout<<"No"<<endl;
    }
    else
    {
        int i=0;//pointer for s1
        int j=0;//pointer for s2
        int k=0;//pointer for s3
        while(k<n3)
        {
            if(s3[k]==s1[i])
            {
                i++;
            }
            else if(s3[k]==s2[j])
            {
                j++;
            }
            k++;
        }
        if(i<n1 || j<n2)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
}

int main()
{
    string str1="xy";
    string str2="12";
    string str3="x12y";
    //string str3="12xy";
    //string str3="x1y2";
    //string str3="x2y1";
    validstr3pointer(str1,str2,str3);
}

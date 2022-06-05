#include <bits/stdc++.h>

using namespace std;

//method 1- using unordered map O(n1+n2+n3) time and O(1) space
void commonmap(int a1[], int a2[], int a3[], int n1, int n2, int n3)
{
    unordered_map<int, int>m1,m2,m3;
    vector<int>v;
    for(int i=0;i<n1;i++)
    {
        m1[a1[i]]++;
    }
    for(int i=0;i<n2;i++)
    {
        m2[a2[i]]++;
    }
    for(int i=0;i<n3;i++)
    {
        m3[a3[i]]++;
    }
    for(int i=0;i<n1;i++)
    {
        if(m1[a1[i]] && m2[a1[i]] && m3[a1[i]])
        {
            v.push_back(a1[i]);
            m1[a1[i]]=0;
        }
    }
    for(auto it:v)
    {
        cout<<it<<" ";
    }
}

// Method 2- 3 pointer approach O(n1+n2+n3) time and O(n1+n2+n3) space
void common3pointer(int a1[], int a2[], int a3[], int n1, int n2, int n3)
{
    int i=0;
    int j=0;
    int k=0;
    set<int>s;
    while(i<n1 && j<n2 && k<n3)
    {
        if(a1[i]==a2[j] && a2[j]==a3[k] && a3[k]==a1[i])
        {
            s.insert(a1[i]);
            i++;
            j++;
            k++;
        }
        else
        {
        int minn= min(a1[i],min(a2[j],a3[k]));
        if(a1[i]==minn)
        {
            i++;
        }
        else if(a2[j]==minn)
        {
            j++;
        }
        else if(a3[k]==minn)
        {
            k++;
        }
        }
    }

    for(auto it:s)
    {
        cout<<it<<" ";
    }
}

int main()
{
    int a1[]= {1, 5, 10, 20, 40, 80};
    int a2[]= {6, 7, 20, 80, 100};
    int a3[]= {3, 4, 15, 20, 30, 70, 80, 120};
    /*int a1[]= {3,3,3};
    int a2[]= {3,3,3};
    int a3[]= {3,3,3};*/
    int n1= sizeof(a1)/sizeof(a1[0]);
    int n2= sizeof(a2)/sizeof(a2[0]);
    int n3= sizeof(a3)/sizeof(a3[0]);
    //common3pointer(a1,a2,a3,n1,n2,n3);
    commonmap(a1,a2,a3,n1,n2,n3);
}


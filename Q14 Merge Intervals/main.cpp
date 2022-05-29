#include <bits/stdc++.h>

using namespace std;
//method 1- using stacks for O(n*lgn) time and O(n) space
void merge_intervals_stacks(vector<pair<int, int>> &a, int n)
{
    stack<pair<int,int>> s;
    s.push({a[0].first,a[0].second});
    for(int i=1;i<n;i++)
    {
       int top_start= s.top().first;
       int top_end= s.top().second;
       int current_start= a[i].first;
       int current_end= a[i].second;

       if(current_start<=top_end)
       {
           s.pop();
           top_end=max(top_end,current_end);
           s.push({top_start,top_end});
       }
       else
       {
           s.push({current_start,current_end});
       }
    }

    while(!s.empty())
    {
        cout<<s.top().first<<" "<<s.top().second<<endl;
        s.pop();
    }
}

//method 2- 2 pointer approach for O(n*lgn) time and O(1) space
void merge_intervals_2pointer(vector<pair<int, int>> &a, int n)
{
    int i=0;
    int j=1;
    while(j<n)
    {
        int start1= a[i].first;
        int end1= a[i].second;
        int start2= a[j].first;
        int end2= a[j].second;
        if(end1>=start2)
        {
            a[i].second= max(end1, end2);
            j++;
        }
        else
        {
            i++;
            a[i].first=start2;
            a[i].second=end2;
            j++;
        }
    }

    for(int k=0;k<=i;k++)
    {
        cout<<a[k].first<<" "<<a[k].second<<endl;
    }
}

int main()
{
   vector<pair<int, int>> a;
   a.push_back({1,3});
   a.push_back({2,6});
   a.push_back({8,10});
   a.push_back({15,18});
   int n= a.size();
   sort(a.begin(),a.end());
   //merge_intervals_stacks(a,n);
   merge_intervals_2pointer(a,n);
}

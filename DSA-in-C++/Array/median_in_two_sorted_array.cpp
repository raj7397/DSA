#include <iostream>
#include <vector>
#include <climits>

using namespace std;


double MedianOfArrays(vector<int>& array1, vector<int>& array2)
{

        int n1 = array1.size();
        int n2 = array2.size();
        if(n1 > n2)
        {
            vector<int>temp = array1;
            array1 = array2;
            array2 = temp;
        }
        n1 = array1.size();
        n2 = array2.size();
     /*  // cout<<"After swap:"<<endl;
        //cout<<"Array1: "<<endl;
        for(int i = 0; i < array1.size(); i++)
        {
            cout<<array1[i]<<" ";
        }
        //cout<<endl;
        //cout<<"Array2: "<<endl;
        for(int i = 0; i < array2.size(); i++)
        {
            cout<<array2[i]<<" ";
        }
        cout<<endl;*/

        int start = 0, end = n1;
        int pos = (n1 + n2 + 1)/2;
        while(start <= end)
        {
           // cout<<"start: "<<start<<"end: "<<end<<endl;
            int i1 = (start + end)/2;
            int i2 = pos - i1;
            int max1 = (i1 == 0) ?INT_MIN: array1[i1 - 1];
            int max2 = (i2 == 0) ? INT_MIN: array2[i2 - 1];
            int min1 = (i1 == n1 )? INT_MAX : array1[i1];
            int min2 = (i2 == n2) ? INT_MAX : array2[i2];
            if(max2 <= min1 && max1 <= min2)
            {
                if((n1 + n2) %2 ==0)
                {
                    double ans = (double)(max(max1, max2) + min(min1,min2))/2;
                    cout<<"ans : "<<ans<<endl;
                    return ans;
                }
                else{
                    double ans = (double)max(max1, max2);
                    return ans;
                }
            }
            if(max2 > min1)
            {
                start = i1 + 1;
            }
            else{
                end = i1 - 1;
            }
        }
        return -1;
}
int main(int argc, char ** argv)
{
        int n1,n2;
        cin>>n1;
        vector<int>arr1(n1);
        for(int i = 0; i <n1; i++)
        {
            cin>>arr1[i];
        }
        cin>>n2;
        vector<int>arr2(n2);
        for(int i = 0; i <n2; i++)
        {
            cin>>arr2[i];
        }
        double ans = MedianOfArrays(arr1, arr2);
        cout<<"ans: "<<ans<<endl;
}
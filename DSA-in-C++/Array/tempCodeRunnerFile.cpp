void sorted_insert(vector<int>&arr1,int i, int x)
{
   // cout<<"x: "<<x<<endl;
    int j = i - 1;
    while(arr1[j] > x)
    {
        j--;
    }
    j++;
    arr1.insert(arr1.begin() + j, x);

}
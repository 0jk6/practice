class Solution 
{
    public:
    //Function to find minimum number of pages.
    int canAllocate(int arr[], int n, int m, int pages){
        int sum = 0; //this will make sure that the pages allocated is less than mid
        int count = 0; //this will track the number of students who got books
        
        //now loop through the array
        for(int i=0; i<n; i++){
            //if sum + arr[i] is greater than pages
            //then, we will increment counter, saying that we gave sum pages to a student
            if(sum + arr[i] > pages){
                count++;
                sum = arr[i]; //reassign sum to arr[i], this is for new student
                if(sum > pages) //if sum is greater than pages, it is not valid, return 0
                    return 0;
            }
            else{
                //if sum+arr[i] is less than pages, add arr[i] to the sum
                sum = sum + arr[i];
            }
        }
        
        //for mid pages, we counted number of students that can be alloted
        //if it is greater than students number, return false, else return true
        if(count < m)
            return 1;
            
        return 0;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += arr[i];
            
        int low = *min_element(arr, arr+n); //minimum answer possible
        int high = sum; //maximum answer possible
        
        //now answers will lie between low and high, and we can apply binary search
        int mid;
        while(low <= high){
            //mid is the number of pages that is the maximum we will allocate 
            //for all the students.
            //eg: if we have 4 students and mid = 100
            //we will allocate pages to students such that, every student will
            //only have less than 100 pages
            mid = low + (high - low)/2;
            
            if(canAllocate(arr, n, m, mid)){
                //if pages can be allocated to students such that they are less than mid
                //we can say that we can also allocate pages to students for all values
                //that are greater than mid. But, what we want is to find the minimum
                //number of pages. To do this, we need to find the number less than mid
                //so, bring high pointer to mid-1
                high = mid-1;
            }
            else{
                //if we cannot allocate pages for students less than mid,
                //then we can strictly say that we can't allocate pages for values
                //less than mid. So, we increment the low pointer to mid+1
                low = mid+1;
            }
            
        }
        
        return low;

    }
};
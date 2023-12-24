#include <iostream>

/*
                        Q. longest consecutive sequence

                    explanation - given array -> arr[] = {102, 4, 100, 1, 101, 3, 2, 1, 1}
                                    we can rearrange it, reorder it in any manner
                                    we can get consecutive sequence as - {1, 2, 3, 4}, len = 4
                                                                    and  {100, 101, 102}, len = 3
                                    so the answer for this question will be the sequence with len = 4

                Brute force -  we take an element as 'x' and try to find 'x+1', 'x+2', ..so on and keep a counter and longest
                                1st we take x=102 from the array, iterate through array to find 'x+1' but there is 
                                no 'x+1' for 102, so we leave 102 at cnt = 1 and move to next element
                                then we take x=4 from the array, iterate through array to find 'x+1' but there is 
                                no 'x+1' for 4, so we leave 102 at cnt = 1 and move to next element
                                we take x=100 from the array, iterate through array to find 'x+1' which is 101, cnt = 2
                                'x+2' = 102 cnt = 3, and long = 3 now there is no x+3   moving to next element
                                x = 1  cnt = 1,  x+1 = 2  cnt = 2,  x+2 = 3  cnt = 3,  x+3 = 4  cnt = 4  got long = 4

        Pseudo code
longest = 1
for(i=0; i < n; i++)
{
    x = arr[i]
    cnt = 1

    while(ls(arr, x+1) == true)         // ls = linear search
    {
        x= x+ 1;
        cnt = cnt + 1;
    }
}


                TC - O(N) * O(N)
                   - O(N^2)         // nearly
                SC - O(1)



                Better sol -  for better solution we have taken a longer array
                            arr[] = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2}

                            firstly we will sort the given to get consecutive elements
                            sort  = {1, 1, 1, 2, 2, 2, 3, 3, 4, 100, 100, 101, 101, 102}

                            we will take each element and move fwd to get greater nmbr, in other words
                            when we move fwd we feed on "last smaller" when previous one is 1 lesser than
                            current one.  also we will take longest and counter of current one

                            lets start as
                            lastSmaller = INT_MIN,  cntcurr = 0,  longest = 0

                            lets take element '1' of index '0'
                            lastSmaller = 1,  cntcurr = 1,  longest = 1

                            lets take element '1' of index '1'
                            lastSmaller = 1,  cntcurr = 1,  longest = 1
                            we will not take bcz lastSmaller is still '1'

                            lets take element '1' of index '2'
                            lastSmaller = 1,  cntcurr = 1,  longest = 1
                            we will not take it

                            lets take element '2' of index '3'
                            lastSmaller = 2,  cntcurr = 2,  longest = 2

                            lets take element '2' of index '4'
                            lastSmaller = 1,  cntcurr = 1,  longest = 2
                            we will not take it

                            similarly
                            lets take element '100' of index '9'
                            lastSmaller = 100,  cntcurr = 1,  longest = 4
                            100 is not consecutive of 4 it has to 99,  bcz of this we will start afresh

                            and so on ..

        pseudo code
sort(); longest = 1; cntarr = 0; lastSmall = INT_MIN
for(i = 0 -> n)
{
    if(arr[i] - 1 == lastSmaller)
    {
        cnt = cnt + 1
        lastSmaller = arr[i]
    }
    else if (arr[i] != lastSmaller)         // in case there is no sequence like with 100
    {
        cnt = 1
        lastSmaller = arr[i]
    }
    longest = max(longest, currcnt)
}



        Actual code
int longestSuccessiveElements(vector<int> &nums)
{
    if(nums.size() == 0)
        return 0;

    sort(nums.begin(), nums.end());             // O(N * log N)
    int n = nums.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for(int i = 0; i < n; i++)                  // O(N)
    {
        if(nums[i] - 1 == lastSmaller)
        {
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if(lastSmaller != nums)
        {
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

                TC - O(N * log N) + O(N)



                Optimal sol -  arr[] = {102, 4, 100, 1, 101, 3, 2, 1, 1}

                                step1 - put everything into set data structure (unordered set)
                                            | 102 |
                                            |  4  |
                                            | 100 |
                                            |  1  |
                                            | 101 |
                                            |  3  |
                                            |  2  |
                                            _______
                                              set

                                        now take 102 and check if there is a nmbr which is just 1 lesser than 102, which is 101
                                        so there is no need to start from 102
                                        same goes for other elements, so we just take 1 & 100 and iterate for consecutive sequence
                                                we are just checking if there is previous element 

        Actual code
int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if(n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;
    for(int i = 0; i < n; i++)                  // O(n )
    {
        st.insert(a[i]);
    }

    for(auto it : st)
    {
        if(st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st. end())
            {
                x = x+ 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}


                TC - O(3N)
                SC - O(N)
*/

int main()
{
    std::cout << "Hello World!\n";
}
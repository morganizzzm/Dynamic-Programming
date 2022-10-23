int longestIncreasingSupersequence(int nums[], int length){

    int memoize[length] ;
    for (int i = 1; i<length; i++) {
        memoize[i] = 0;
    }
    memoize [0] = 1;
    for (int i = 1; i<length; i++){
        for (int j=0 ; j<i; j++){
            memoize[i] = (nums[i]>nums[j] & memoize[i]<memoize[j]) ?
                    memoize[j]:memoize[i];
        }
        memoize[i]++;

    }
    return *std::max_element(memoize, memoize +length);;
}

int longestCommonSubsequence(std::string first, std::string second){
    if (first.empty() || second.empty()){
        return 0; 
    }
    int memoize[first.size()][second.size()];
    memoize[0][0] = (first[0] == second[0]);
    for (int i = 1; i<second.size(); i++){
        memoize[0][i] = first[0]==second[i]? 1 : memoize[0][i-1];
    }

    for (int i = 1; i<first.size(); i++){
        memoize[i][0] = first[i]==second[0]? 1 : memoize[i-1][0];
    }
    
    for (int i=1; i< first.size(); i++){
        for (int j=1; j< second.size(); j++){
            int max = std::max (memoize[i][j-1], memoize[i-1][j]);
            if (first.at(i) == second.at(j)) {
                memoize[i][j] = max+1;
            }
            else {
                memoize[i][j] = max;
            }
        }
    }
    return memoize[first.size()-1][second.size()-1];
}

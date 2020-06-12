bool canplace(vector<vector<char>>&A,int n,int row,int col, int num)
{
    char ch=num+'0';
    for(int x=0;x<n;x++)
    {
        if(A[row][x]==ch || A[x][col]==ch)
        return false;
    }
    
    int rn=sqrt(n);
    int boxr=row/rn;
    int boxc=col/rn;
    int br=boxr*rn;
    int bc=boxc*rn;
    for(int i=br;i<br+rn;i++)
    {
        for(int j=bc;j<bc+rn;j++)
        {
            if(A[i][j]==ch)
            return false;
        }
    }
    
    return true;
}




bool solve(vector<vector<char> > &A, int n, int row, int col)
{
    if(row==n)
    return true;
    
    if(col==n)
    return solve(A,n,row+1,0);
    
    if(A[row][col]!='.')
    {
        return solve(A,n,row,col+1);
    }
    
    for(int curr=1;curr<=n;curr++)
    {
        if(canplace(A,n,row,col,curr)==true)
        {
            A[row][col]=curr+'0';
            bool suc= solve(A,n,row,col+1);
            if(suc==true)
            {
                return true;
            }
            
            A[row][col]='.';
        }
    }
    
    return false;
}



void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n=A.size();
    solve(A,n,0,0);
}

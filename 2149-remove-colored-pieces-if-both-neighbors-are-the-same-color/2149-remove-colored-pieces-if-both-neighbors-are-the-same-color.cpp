class Solution {
public:
    bool winnerOfGame(string color) {
        //we first take three consecutive pointers
        int i =0 ; 
        int j = i+1 ;
        int k = i + 2 ;
        int countA =0 ;
        int countB = 0 ;
        while(k<color.size()){
            if(color[i] == 'A' && color[j] == 'A' && color[k] == 'A'){
                countA++ ; //if we a get valid move for alice
            }
            if(color[i] == 'B' && color[j] == 'B' && color[k] == 'B'){
                countB++ ; //if we get a valid move for bob
            }
            i++ ;
            j++ ;
            k++ ;
        }
        if(countA > countB){
            return true ;
        }
        else{
            return false ;
        }
    }
};
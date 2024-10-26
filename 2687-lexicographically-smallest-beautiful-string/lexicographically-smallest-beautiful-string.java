class Solution {
    public String smallestBeautifulString(String S, int K) {
        int N=S.length();
         char[] s = S.toCharArray();
        for(int i = N -1; i >=0; i--){
            for(char ch = (char)(s[i] +1); ch < 'a' + K; ch++){
                if(isValid(s, i, ch)){
                    s[i] = ch;
                    boolean possible = true;
                    for(int j = i +1; j < N; j++){
                        boolean found = false;
                        for(char c = 'a'; c < 'a' + K; c++){
                            if(isValid(s, j, c)){
                                s[j] = c;
                                found = true;
                                break;
                            }
                        }
                        if(!found){
                            possible = false;
                            break;
                        }
                    }
                    if(possible){
                        return new String(s);
                    }
                }
            }
        }
        return "";
    }
     public static boolean isValid(char[] s, int pos, char ch){
        if(pos >=1 && s[pos -1] == ch){
            return false;
        }
        if(pos >=2 && s[pos -2] == ch){
            return false;
        }
        return true;
    }
}
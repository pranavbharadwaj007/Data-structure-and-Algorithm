
// Link : https://practice.geeksforgeeks.org/problems/finding-profession3834/1

    char profession(int n, int pos){
    bool flip = false ;
    while(pos != 1){
        if(pos%2 == 0)
            flip = !flip ;
        pos = (pos+1)/2 ;
    }
    return (flip ? 'd' : 'e') ;
    }

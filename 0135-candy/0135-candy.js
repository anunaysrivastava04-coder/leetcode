var candy = function(ratings) {
    let n= ratings.length;
    let ltr= Array(n).fill(1);
    for(let i=1; i<ltr.length; i++){
        if(ratings[i-1] < ratings[i]){
            ltr[i] = ltr[i-1] + 1;
        }
    }
    let rtl= Array(n).fill(1);
    for(let i=n-2; i>=0; i--){
        if(ratings[i+1] < ratings[i]){
            rtl[i] = rtl[i+1] + 1;
        }
    }
    let sumCandy=0;
    for(let i=0; i<n; i++){
        sumCandy = sumCandy + Math.max(ltr[i], rtl[i]);
    }
    return sumCandy;
};
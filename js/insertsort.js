'use strict';
//Insertion-Sort
const a = [10,3,2,4,51,23,43,55,23,66,34,67,30];

for(let i = 1; i < a.length; ++i) {
    let key = a[i];
    let j = i - 1;
    while(j>=0 && a[j]>key) {
        a[j + 1] = a[j];
        j = j - 1;
    }
    a[j + 1] = key;
}

console.log(a)

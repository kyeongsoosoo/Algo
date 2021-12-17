    // while(pointerA < n && pointerB >= 0){
    //     int sum = subsetA[pointerA] + subsetB[pointerB];

    //     cout << sum << '\n';
        
    //     if(sum < T){
    //         pointerA += 1;
    //         continue;
    //     }
    //     else if(sum > T){
    //         pointerB -= 1;
    //         continue;
    //     }
    //     else{
    //         while(subsetA[pointerA] == subsetA[pointerA + 1]){
    //             pointerA += 1;
    //             sum += 1;
    //         }
    //         while(subsetB[pointerB] == subsetB[pointerB + 1]){
    //             pointerB += 1;
    //             sum += 1;
    //         }
    //         pointerA += 1;
    //         pointerB -= 1;
    //     }
    // }
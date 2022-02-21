
// function countDepth(inpArray) {
//     let depth = 0;
//     if (typeof(inpArray) == 'object') {
//         depth++;
//         subarray = inpArray;

//         for (let i = 0; i < subarray.length; i++)
//             if (typeof(subarray[i]) == 'object') {
//                 depth++;
//                 subarray = subarray[i];
//                 i = 0;
//             }

//     }
//     console.log("Depth=", depth)
// }


function countDepth(inp, count) {
    arr.forEach(element => {
        if (typeof element == 'object')
            count = depth(element, count=count+1);
    });
    return count;
}

input = [1,2,3]
countDepth(input,1)
input = [1,[2,[3,4]]]
console.log(countDepth(input,1 ))
input = [1,[2,3,[4,[5,[7,8]]]]]
console.log(countDepth(input,1))

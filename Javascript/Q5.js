function countDepth(inp, count) {
    inp.forEach(element => {
        if (Array.isArray(element))
            count = countDepth(element, count=count+1);
    });
    return count;
}

input = [1,2,3]
console.log(`Depth is= ${countDepth(input,1 )}`)
input = [1,[2,[3,4]]]
console.log(`Depth is= ${countDepth(input,1 )}`)
input = [1,[2,3,[4,[5,[7,8]]]]]
console.log(`Depth is= ${countDepth(input,1 )}`)

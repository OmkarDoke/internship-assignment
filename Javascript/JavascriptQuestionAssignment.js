


function getSubarray(input) {

    let result = input.filter(element => {
        return /[0-9]/.test(element)
    });
    return result;
}

function printLoneOnces(input) {
    input.forEach(element => {
            let count = 0;
            let number = element.toString();
            for (let i = 0; i < number.length; i++) {
                if (number[i] == "1" && number[i + 1] != "1" && number[i - 1] != "1")
                    count++;
            }
            console.log(element + " count of lone 1=>", count)
        }

    );
}


function getFinalProduct(...args) {
    let sum = 0;
    for (let arg of args)
        sum += arg;
        console.log("Arg Sum:",sum);
        if (sum<0)
        sum*=-1
    while (sum > 9) {
        
        let digitProduct = 1;
        let temp = sum.toString()
        for (digit of temp) {
            digitProduct *= digit;
            sum = parseInt(digitProduct)
        }
        console.log("Digit's product:",sum);

        // sum = digitProduct;
    }

    console.log("final single digit product:",sum);

}

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
function countDepth(inpArray,count) {
    // let depth = 0;
   inpArray.forEach(element =>
    {
        if(typeof(element)=='object')
         count= countDepth(element,count=count+1)
    });
    
    return count;
}

function convertInto(input) {
    let result = "";
    if (input.includes("=>")) {
        let [fname , parameters]=input.split("=")
        fname=fname.split(" ")[1]
        let body=input.split("=>")[1]
        result += `function ${fname}${parameters} { \n ${body} \n}`
    } else {
        let nameStart=input.indexOf(" ");
        let firstPara = input.indexOf("(");
        let lastPara = input.indexOf(")");
        let functionName=input.slice(nameStart,firstPara);
        let parameters = input.slice(firstPara, lastPara + 1)
        let body = input.slice(lastPara + 1)
        result = `let ${functionName}=${parameters} =>\n${body} `
    }
    console.log(result)

}

//Q1

// //Q2
// input = ["first", "second", "3rd", "fifth", "input5", "omkar99doke"]
// let result = getSubarray(input)
// console.table(result)

// //Q3
// input = [1, 11, 25, 104, 1001, 123451, 841,100111]
printLoneOnces(input)


// //Q4
// getFinalProduct(1, 2,-100, 3)
// getFinalProduct(1, 5, 6, 8,-44, 9,234,12)

// //Q5
// input = [1,2,3]
// countDepth(input)
// input = [1,[11,12],[1,34],[2,[3,4]]]
// console.log(countDepth(input,1 ))// input = [1,[2,[3,4,[5,6,[7,8]]]]]
// countDepth(input)


// //Q6
input=""
input='let pow=(x,y) => console.log(x**y)'
convertInto(input)
input = 'function inp(x,y){ console.log(x+y)}'
convertInto(input)
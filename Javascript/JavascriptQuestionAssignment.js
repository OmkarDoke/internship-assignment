function getBoomerangs(input) {
    let result = [];
    for (let index = 0; index < input.length - 2; index++) {
        let firstNum = input[index]
        let secondNum = input[index + 1];
        let thirdNum = input[index + 2];
        if (firstNum == thirdNum && firstNum != secondNum)
            result.push([firstNum, secondNum, thirdNum])
    }
    return result;
}


function getSubarray(input) {

    let result = input.filter(element => {
        for (x of element)
            if (x >= 48 || x <= 58) {
                return element;
            }
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

function countDepth(inpArray) {
    let depth = 0;
    if (typeof(inpArray) == 'object') {
        depth++;
        subarray = inpArray;

        for (let i = 0; i < subarray.length; i++)
            if (typeof(subarray[i]) == 'object') {
                depth++;
                subarray = subarray[i];
                i = 0;
            }

    }
    console.log("Depth=", depth)
}

function convertInto(input) {
    let result = "";
    if (input.includes("=>")) {
        let [parameters, body] = input.split("=>")
        result = "function Output " + parameters
        if (body[1] == "{")
            result = result + "\n " + body
        else
            result += " { \n " + body + "\n}"
    } else {
        let firstPara = input.indexOf("(")
        let lastPara = input.indexOf(")")
        let parameters = input.slice(firstPara, lastPara + 1)
        let body = input.slice(lastPara + 1)
        result = `${parameters} =>\n${body}`
    }
    console.log(result)

}

//Q1
// input = [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2];
// console.log("Input array:", input);

// let Boomerangs = getBoomerangs(input);
// console.log("Boomerangs are:", Boomerangs);

// //Q2
// input = ["first", "second", "3rd", "fifth", "input5", "omkar99doke"]
// let result = getSubarray(input)
// console.log(result)

// //Q3
// input = [1, 11, 25, 104, 1001, 123451, 841,100111]
// printLoneOnces(input)


//Q4
getFinalProduct(1, 2,-100, 3)
getFinalProduct(1, 5, 6, 8,-44, 9,234,12)

// //Q5
// input = [1,2,3]
// countDepth(input)
// input = [1,[2,[3,4]]]
// countDepth(input)
// input = [1,[2,[3,4,[5,6,[7,8]]]]]
// countDepth(input)


// //Q6
// input=""
// input='(x,y,z) => console.log(x)'
// convertInto(input)
// input = 'function inp(x,y){ console.log(x+y)}'
// convertInto(input)
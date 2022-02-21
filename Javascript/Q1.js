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


input = [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2];
console.log("Input array:", input);

let Boomerangs = getBoomerangs(input);
console.log("Boomerangs are:", Boomerangs);

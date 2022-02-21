function getSubarray(input) {

    let result = input.filter(element => {
        return /[0-9]/.test(element)
    });
    return result;
}

input = ["first", "second", "3rd", "fifth", "input5", "omkar99doke"]
let result = getSubarray(input)
console.log("input=",input);
console.table(result)

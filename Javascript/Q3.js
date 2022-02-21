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

input = [1, 11, 25, 104, 1001, 123451, 841,100111]
printLoneOnces(input)
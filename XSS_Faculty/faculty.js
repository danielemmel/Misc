/**
 * JavaScript faculty implementation that is vulnerable to XSS (assuming that num is not type checked before calling the function and attacker-controllable)
 * Exists solely for amusement. Should not be used. (Is probably also quite inefficient.)
 * 
 * @param {*} num The number (or not) to calculate the faculty of.
 * @returns The faculty of the given number or undefined if the faculty is not defined for this input.
 */
function faculty(num) {
    let facStr = num.toString();
    if(num < 2) {
        return undefined;
    }
    for(let i = num - 1; i > 1; i--) {
        facStr += "*" + i;
    }
    return eval(facStr);
  }

function demo() {
    console.log(`Faculty of 3 is: ${faculty(3)}`);
    console.log(`Faculty of 6 is: ${faculty(6)}`);
    console.log(`Faculty of 1 is: ${faculty(1)}`);

    console.log('--- XSS example --- ');
    faculty('console.log("XSS triggered!"); //');
}  
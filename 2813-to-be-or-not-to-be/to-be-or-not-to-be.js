/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe: function(val2){
            if(val2 !=  null && val === val2 ) return  true ;
            else throw "Not Equal";
        },
        notToBe: function(val3){
            if(val !== val3) return true;
            throw "Equal";
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
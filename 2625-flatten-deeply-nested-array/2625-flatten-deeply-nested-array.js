/**
 * @param {Array} arr
 * @param {number} n
 * @return {Array}
 */
var flat = function (arr, n) {
  let result = [];

  function flatten(innerArr, depth) {
    for (let item of innerArr) {
      if (Array.isArray(item) && depth > 0) {
        flatten(item, depth - 1); 
      } else {
        result.push(item);
      }
    }
  }

  flatten(arr, n);
  return result;
};

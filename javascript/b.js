var wrapper = require('./a.js').wrapper;
function aas(q, t) {
    console.log("inside sameer function", a);
    throw "sameer";
}
var wrap = wrapper(aas);
wrap("sameer", "kumar");
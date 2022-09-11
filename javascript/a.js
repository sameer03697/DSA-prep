var wrapper = (fn) => {
    return function () {
        var args = [...arguments, "HELLO"];
        try {
            console.log.apply(this, args);
            return fn.apply(this, arguments);
        } catch (ex) {
            throw ex;
        }
    };
};
module.exports = {
    wrapper
}
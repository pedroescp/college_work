var assert  = require('assert');
var arrayList = require('../src/app')

describe('Array', function(){
    describe('#indexOF()', function() {
        it('shoud return -1 when the vlaue is not present', function (){
            assert.equal(arrayList.indexOf(4), -1);
        });
    })
})
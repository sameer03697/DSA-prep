describe('handlePOSTProductProvisionRequestPayload', () => {
    let req;
    beforeEach(() => {
        req = {
            user: {
                country: "US",
                encryptedAccountNumber: "AAAAAAAA",
            },
            session: {
                context: {
                    getProduct: () => 'payin'
                }
            }
        }
    })

    it('should exist', () => {
        expect(typeof handlePOSTProductProvisionRequestPayload).toBe('function');
    })
    it('should return expected product provision request', () => {
        let output = {
            "method": "POST",
            "path": "/v1/customer/merchant-onboarding/large-entity/payor/provision",
            "body": {
                "subject_entity_number": "AAAAAAAA",
                "subject_entity_type": "ACCOUNT",
                "mode": "APPLY",
                "products": [{
                    "product_name": "PAYIN",
                    "country": "US",
                    "features": [{ "feature_name": "feature1" }, { "feature_name": "feature2" }]
                }]
            },
            "headers": { "Content-Type": "application/json" }
        }
        expect(handlePOSTProductProvisionRequestPayload(req)).toEqual(output);
    })

    it('should return expected output with addtional features', () => {
        let output = {
            "method": "POST",
            "path": "/v1/customer/merchant-onboarding/large-entity/payor/provision",
            "body": {
                "subject_entity_number": "AAAAAAAA",
                "subject_entity_type": "ACCOUNT",
                "mode": "APPLY",
                "products": [{
                    "product_name": "PAYIN",
                    "country": "US",
                    "features": [{ "feature_name": "feature1" }, { "feature_name": "feature2" }, { "feature_name": "addtionalFeature1" }, { "feature_name": "addtionalFeature2" }]
                }]
            },
            "headers": { "Content-Type": "application/json" }
        }
        expect(handlePOSTProductProvisionRequestPayload(req, ["addtionalFeature1", "addtionalFeature2"])).toEqual(output)
    })
})
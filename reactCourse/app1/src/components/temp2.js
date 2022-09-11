const buildPOSTProductProvisionRequestBody = (req, addtionalFeatures = []) => {
    const supportedFeatures = addtionalFeatures;

    const productName = {
        payout: 'PAYOUTS',
        payin: 'PAYIN'
    }

    const getProductFeatures = (productName) => {
        let features = defaultProductFearureMap[productName];
        features = features.concat(supportedFeatures);
        let result = features.map((item) => {
            return {
                "feature_name": item
            }
        })
        return result;
    }


    const products = [productName[req.session.context.getProduct()]];
    const getProducts = (products) => {
        return products.map(product => {
            let result = {
                product_name: product,
                country: _.get(req, 'user.country')
            }
            let productFeatures = getProductFeatures(product);
            if (productFeatures.length) result.features = productFeatures;
            return result;
        });
    }
    const payload = {
        subject_entity_number: _.get(req, 'user.encryptedAccountNumber'),
        subject_entity_type: "ACCOUNT",
        mode: "APPLY",
        products: getProducts(products),
    }
    return payload
}

//
// Copyright (c) 2016 by ACI Worldwide, Inc.
// All rights reserved.
//
// This software is the confidential and proprietary information
// of ACI Worldwide Inc ("Confidential Information"). You shall
// not disclose such Confidential Information and shall use it
// only in accordance with the terms of the license agreement
// you entered with ACI Worldwide Inc.
//

#import <Foundation/Foundation.h>
@class OPPTransactionProcessor;
@class OPPPaymentParams;

/// An enumeration for the various types of transaction.
typedef NS_ENUM(NSInteger, OPPTransactionType) {
    /// The synchronous transaction.
    OPPTransactionTypeSynchronous,
    /// The asynchronous transaction.
    OPPTransactionTypeAsynchronous,
    /// The transaction is undefined.
    OPPTransactionTypeUndefined
};

/**
 Class to encapsulate the parameters needed for performing transaction.
 */

NS_ASSUME_NONNULL_BEGIN
@interface OPPTransaction : NSObject

/** @name Initialization methods */

- (instancetype)init NS_UNAVAILABLE;

/**
 
 Creates and returns transaction initialized with payment params.
 
 @param paymentParams The payment parameters for transaction. Must not be nil.
 @see OPPPaymentParams
 */
+ (instancetype)transactionWithPaymentParams:(OPPPaymentParams *)paymentParams;

/**
 Creates and returns transaction initialized with payment params.
 
 @param paymentParams The payment parameters for transaction. Must not be nil.
 @see OPPPaymentParams
 */
- (instancetype)initWithPaymentParams:(OPPPaymentParams *)paymentParams NS_DESIGNATED_INITIALIZER;

/** @name Properties */

/** 
 The parameters representing a concrete payment method are kept as an OPPPaymentParams object.
 
 @see OPPPaymentParams
 */
@property (nonatomic, readonly) OPPPaymentParams *paymentParams;

/**
 The type of the transaction.
 @see OPPTransactionType
 */
@property (nonatomic, readonly) OPPTransactionType type;

/// The URL to the receiver system (e.g. 3-D Secure, PayPal) that the shopper should be forwarded to. The property has nil value on synchronous transaction.
@property (nonatomic, nullable) NSURL *redirectURL;

/// App payment signed request parameters contain seller’s order information which should be forwarded to Alipay native SDK.
@property (nonatomic, copy, readonly, nullable) NSString *alipaySignedOrderInfo;

@end
NS_ASSUME_NONNULL_END

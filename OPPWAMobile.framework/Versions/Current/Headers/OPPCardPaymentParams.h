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
#import "OPPPaymentParams.h"

/**
 Class to represent a set of card parameters needed for performing an e-commerce card transaction.

 It offers сonvenience methods for checking if the number is valid, i.e. if it passes the Luhn check and can be assigned to one of the major card companies.
 
 After getting an authorization for the transaction the parameters are masked in accordance to PCI PA DSS requirements.
 */

NS_ASSUME_NONNULL_BEGIN
@interface OPPCardPaymentParams : OPPPaymentParams

/** @name Initialization methods */

- (instancetype)initWithCheckoutID:(NSString *)checkoutID paymentBrand:(NSString *)paymentBrand error:(NSError * _Nullable __autoreleasing *)error NS_UNAVAILABLE;

/**
 Creates an object representing a card transaction.

 @param checkoutID The checkout ID of the transaction. Must be not nil or empty.
 @param paymentBrand The payment brand of the card.
 @param holder The name of the card holder.
 @param number The card number of the transaction.
 @param expiryYear The expiration year. It is expected in the format YYYY.
 @param expiryMonth The expiration month of the card. It is expected in the format MM.
 @param CVV The CVV code associated with the card. Set to nil if CVV is not required.
 @param error The error that occurred while validating payment parameters. See code attribute (OPPErrorCode) and NSLocalizedDescription to identify the reason of failure.
 @return Returns an object representing a card transaction, and nil if parameters are invalid.
*/
+ (nullable instancetype)cardPaymentParamsWithCheckoutID:(NSString *)checkoutID paymentBrand:(NSString *)paymentBrand holder:(NSString *)holder number:(NSString *)number expiryMonth:(NSString *)expiryMonth expiryYear:(NSString *)expiryYear CVV:(nullable NSString *)CVV error:(NSError **)error;

/**
 Creates an object representing a card transaction.
 @param checkoutID The checkout ID of the transaction. Must be not nil or empty.
 @param paymentBrand The payment brand of the card.
 @param holder The name of the cardholder.
 @param number The card number of the transaction.
 @param expiryYear The expiration year. It is expected in the format YYYY.
 @param expiryMonth The expiration month of the card. It is expected in the format MM.
 @param CVV The CVV code associated with the card. Set to nil if CVV is not required.
 @param error The error that occurred while validating payment parameters. See code attribute (OPPErrorCode) and NSLocalizedDescription to identify the reason of failure.
 @return Returns an object representing a card transaction, and nil if parameters are invalid..
 */
- (nullable instancetype)initWithCheckoutID:(NSString *)checkoutID paymentBrand:(NSString *)paymentBrand holder:(NSString *)holder number:(NSString *)number expiryMonth:(NSString *)expiryMonth expiryYear:(NSString *)expiryYear CVV:(nullable NSString *)CVV error:(NSError **)error NS_DESIGNATED_INITIALIZER;

/** @name Properties */

/** Holder of the card account. The length must be greater than 3 characters and less then 128 character. */
@property (nonatomic, copy, readonly) NSString *holder;

/** The card number. It may contain spaces " " and dashes "-". */
@property (nonatomic, copy, readonly) NSString *number;

/** The card expiry month in the format MM. */
@property (nonatomic, copy, readonly) NSString *expiryMonth;

/** The card expiry year in the format YYYY. */
@property (nonatomic, copy, readonly) NSString *expiryYear;

/** The CVV code found on the card. This is needed for e-commerce transactions. */
@property (nonatomic, copy, readonly) NSString *CVV;

/** Default is NO. If YES, the payment information will be stored for future use. */
@property (nonatomic, getter=isTokenizationEnabled) BOOL tokenizationEnabled;

/** @name Parameter Checks */

/**
 Checks if the holder name is filled with sufficient data to perform a transaction.
 
 @param holder Holder of the card account.
 @return YES if the holder name length greater than 3 characters and less than 128 character.
 */
+ (BOOL)isHolderValid:(NSString *)holder;

/**
 Checks if the number passes the Luhn Test http://en.wikipedia.org/wiki/Luhn_algorithm
 
 @param number Card number.
 @param paymentBrand The payment brand of the card.
 @return YES if the number passes the Luhn test and brand check, NO if it doesn't.
 */
+ (BOOL)isNumberValid:(NSString *)number forPaymentBrand:(NSString *)paymentBrand;

/**
 Checks if the card expiry month is filled with sufficient data to perform a transaction.
 
 @param expiryMonth The expiry month of the card.
 @return YES if the card expiry month is in the format MM.
 */
+ (BOOL)isExpiryMonthValid:(NSString *)expiryMonth;

/**
 Checks if the card expiry year is filled with sufficient data to perform a transaction.
 
 @param expiryYear The expiry year of the card.
 @return YES if the card expiry year is in the format YYYY.
 */
+ (BOOL)isExpiryYearValid:(NSString *)expiryYear;

/**
 Checks if the month and year have been set and whether or not card is expired.
 
 @param month The expiry month of the card.
 @param year The expiry year of the card.
 @return YES if the month or the year is expired. NO if the card is not expired yet.
 */
+ (BOOL)isExpiredWithExpiryMonth:(NSString *)month andYear:(NSString *)year;

/**
 Checks if the card CVV is filled with sufficient data to perform a transaction.
 
 @param CVV The card security code or CVV.
 @param paymentBrand The payment brand of the card.
 @return YES if the card CVV length greater than 3 characters and less than 4 characters depends on card brand.
 */
+ (BOOL)isCvvValid:(NSString *)CVV forPaymentBrand:(NSString *)paymentBrand;

@end

@interface OPPCardPaymentParams (Deprecated)

/**
 Creates an object representing a card transaction.
 
 @param checkoutID The checkout ID of the transaction. Must be not nil or empty.
 @param brand The brand of the card.
 @param holder The name of the card holder.
 @param number The card number of the transaction.
 @param expiryYear The expiration year. It is expected in the format YYYY.
 @param expiryMonth The expiration month of the card. It is expected in the format MM.
 @param CVV The CVV code associated with the card. Set to nil if CVV is not required.
 @param error The error that occurred while validating payment parameters. See code attribute (OPPErrorCode) and NSLocalizedDescription to identify the reason of failure.
 @return Returns an object representing a card transaction, and nil if parameters are invalid.
 @deprecated Use +cardPaymentParamsWithCheckoutID:paymentBrand:holder:number:expiryMonth:expiryYear:CVV:error: instead
 @see +cardPaymentParamsWithCheckoutID:paymentBrand:holder:number:expiryMonth:expiryYear:CVV:error:
 */
+ (nullable instancetype)cardPaymentParamsWithCheckoutID:(NSString *)checkoutID brand:(OPPPaymentParamsBrand)brand holder:(NSString *)holder number:(NSString *)number expiryMonth:(NSString *)expiryMonth expiryYear:(NSString *)expiryYear CVV:(nullable NSString *)CVV error:(NSError **)error DEPRECATED_MSG_ATTRIBUTE("- Use +cardPaymentParamsWithCheckoutID:paymentBrand:holder:number:expiryMonth:expiryYear:CVV:error: instead.");

/**
 Creates an object representing a card transaction.
 
 @param checkoutID The checkout ID of the transaction. Must be not nil or empty.
 @param brand The brand of the card.
 @param holder The name of the cardholder.
 @param number The card number of the transaction.
 @param expiryYear The expiration year. It is expected in the format YYYY.
 @param expiryMonth The expiration month of the card. It is expected in the format MM.
 @param CVV The CVV code associated with the card. Set to nil if CVV is not required.
 @param error The error that occurred while validating payment parameters. See code attribute (OPPErrorCode) and NSLocalizedDescription to identify the reason of failure.
 @return Returns an object representing a card transaction, and nil if parameters are invalid.
 @deprecated Use -initWithCheckoutID:paymentBrand:holder:number:expiryMonth:expiryYear:CVV:error: instead
 @see -initWithCheckoutID:paymentBrand:holder:number:expiryMonth:expiryYear:CVV:error:
 */
- (nullable instancetype)initWithCheckoutID:(NSString *)checkoutID brand:(OPPPaymentParamsBrand)brand holder:(NSString *)holder number:(NSString *)number expiryMonth:(NSString *)expiryMonth expiryYear:(NSString *)expiryYear CVV:(nullable NSString *)CVV error:(NSError **)error DEPRECATED_MSG_ATTRIBUTE("- Use -initWithCheckoutID:paymentBrand:holder:number:expiryMonth:expiryYear:CVV:error: instead.");

/**
 Checks if the number passes the Luhn Test http://en.wikipedia.org/wiki/Luhn_algorithm.
 
 @param number Card number.
 @param brand The brand of the card.
 @return YES if the number passes the Luhn test and brand check, NO if it doesn't.
 @deprecated Use +isNumberValid:forPaymentBrand: instead
 @see +isNumberValid:forPaymentBrand:
 */
+ (BOOL)isNumberValid:(nonnull NSString *)number forBrand:(OPPPaymentParamsBrand)brand DEPRECATED_MSG_ATTRIBUTE("- Use +isNumberValid:forPaymentBrand: instead.");

/**
 Checks if the card CVV is filled with sufficient data to perform a transaction.
 
 @param CVV The card security code or CVV.
 @param brand The brand of the card.
 @return YES if the card CVV length greater than 3 characters and less than 4 characters depends on card brand.
 @deprecated Use +isCvvValid:forPaymentBrand: instead
 @see +isCvvValid:forPaymentBrand:
 */
+ (BOOL)isCvvValid:(NSString *)CVV forBrand:(OPPPaymentParamsBrand)brand DEPRECATED_MSG_ATTRIBUTE("- Use +isCvvValid:forPaymentBrand: instead.");

@end
NS_ASSUME_NONNULL_END

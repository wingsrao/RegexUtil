//
//  RegexUtil.h
//
//  Created by 451406018@qq.com on 16/1/13.
//  Copyright © 2016年 wings. All rights reserved.
//  >>>>>别喷我用英文写注视，外国人根本不看。。。
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    RegexTypeEmail = 1,     //email
    RegexTypeDigit,         //0~9 number
    RegexTypeMoney,         //Chinese RMB e.g. ￥20.88（without the money symbol），can't be ￥01.88
    RegexTypePassword,      //password restrict e.g. password only contains number and character,character must be first
    RegexTypeID,            //China ID.
    RegexTypePhone          //China Phone format
} RegexType;

#define kEmailRegex     @"^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*.\\w+([-.]\\w+)*$"
#define kDigit          @"^[0-9]+$"
#define kMoney          @"^[0-9]+(.[0-9]{2})?$" //100.99
#define kID             @"^(\\d{15})|(\\d{18})|(\\d{17}(\\d|X|x))$" // only check format(15 or 18 numbers),not real
#define kPassword       @"^[a-zA-Z0-9]\\w{6,20}$"
#define kPhone          @"^1[3|4|5|7|8]\\d{9}$"

@interface RegexUtil : NSObject

/**
 *  The method to match the String.
 *
 *  @param str  string to match
 *  @param type which type to match
 *
 *  @return YES if match,NO if not match
 */
+(BOOL)isMatch:(NSString *)str withType:(RegexType)type;
/**
 *  check the real Chinese ID Number
 *
 *  @param value string to check
 *
 *  @return YES if real,NO if not real
 */
+(BOOL)verifyIDCardNumber:(NSString *)value;

@end

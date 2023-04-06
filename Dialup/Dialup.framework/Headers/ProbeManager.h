//
//  ProbeManager.h
//  Dialup
//
//  Created by 樊伟鹏 on 2020/9/29.
//  Copyright © 2020 abc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^successBlock)(NSMutableDictionary * dict);
typedef void(^errorBlock)(NSError * error);
typedef void(^returnBlock)(NSMutableDictionary * dictBack);
typedef void(^eventSeqBlock)(NSString * eventSeq);


//typedef enum : NSUInteger {
//    typeNot,
//    typeProd,
//    typeTest,
//} envType;


@interface ProbeManager : NSObject

@property (nonatomic,assign) BOOL isHTTPS;

//+ (instancetype)initializtion;
+ (instancetype)initializtionWithBusinessCode:(NSString *)businessCode env:(NSString *)env;


/**
 短流程上报接口
 */
- (void)shortProcessReportWithBusinessCode:(NSString *)businessCode clientId:(NSString *)clientId eventCode:(NSString *)eventCode eventName:(NSString *)eventName eventType:(NSString *)eventType eventValue:(NSString *)eventValue eventStatus:(NSString *)eventStatus exceptionCode:(NSString *)exceptionCode exceptionMsg:(NSString *)exceptionMsg apiTime:(NSString *)apiTime;

/**
 长流程上报接口
 */
- (void)longProcessReportWithBusinessCode:(NSString *)businessCode clientId:(NSString *)clientId eventCode:(NSString *)eventCode eventName:(NSString *)eventName eventType:(NSString *)eventType eventTime:(NSString *)eventTime indexCode:(NSString *)indexCode indexValue:(NSString *)indexValue eventStatus:(NSString *)eventStatus exceptionCode:(NSString *)exceptionCode exceptionMsg:(NSString *)exceptionMsg apiTime:(NSString *)apiTime;

/**
 异常数据上报接口
 */
- (void)exceptionReportWithBusinessCode:(NSString *)businessCode clientId:(NSString *)clientId eventCode:(NSString *)eventCode eventName:(NSString *)eventName indexCode:(NSString *)indexCode indexValue:(NSString *)indexValue exceptionCode:(NSString *)exceptionCode exceptionMsg:(NSString *)exceptionMsg apiTime:(NSString *)apiTime;

/**
 上传ping状态
 */
- (void)pingWithBusinessCode:(NSString *)businessCode clientId:(NSString *)clientId ip:(NSString *)ip eventCode:(NSString *)eventCode eventName:(NSString *)eventName eventType:(NSString *)eventType apiTime:(NSString *)apiTime;


/**
 上传dns结果
 */
- (void)dnsWithBusinessCode:(NSString *)businessCode clientId:(NSString *)clientId ip:(NSString *)ip eventCode:(NSString *)eventCode eventName:(NSString *)eventName eventType:(NSString *)eventType apiTime:(NSString *)apiTime;


/**
 上传trace结果
 */
- (void)traceWithBusinessCode:(NSString *)businessCode clientId:(NSString *)clientId ip:(NSString *)ip eventCode:(NSString *)eventCode eventName:(NSString *)eventName eventType:(NSString *)eventType apiTime:(NSString *)apiTime;


/**
 短流程上报接口
 添加参数 eventSeq； 根据eventType区分：1：    生成eventSeq
                                    其他：  使用参数
 */
//- (void)ASshortProcessReportWithBusinessCode:(NSString *)businessCode clientId:(NSString *)clientId eventCode:(NSString *)eventCode eventName:(NSString *)eventName eventType:(NSString *)eventType eventSeq:(NSString *)eventSeq eventValue:(NSString *)eventValue eventStatus:(NSString *)eventStatus exceptionCode:(NSString *)exceptionCode exceptionMsg:(NSString *)exceptionMsg apiTime:(NSString *)apiTime eventSeqBlock:(eventSeqBlock)eventSeqSDK;



@end

NS_ASSUME_NONNULL_END

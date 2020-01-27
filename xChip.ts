/**
 * xChip c++ template
 */
//% weight=99 color=#000000 icon="\uf085"
namespace xChip {
    //%blockId=xChip_begin
    //%block="xChip begin"
    //%shim=xChip::begin
    export function begin(var_: number): number {
        return 1;
    }
    
    //%blockId=xChip_readDeviceID
    //%block="xChip readDeviceID"
    //%shim=xChip::readDeviceID
    export function readDeviceID(deviceIDReg: number): number {
        return 1;
    }
    
    //%blockId=xChip_delay
    //%block="xChip delay"
    //%shim=xChip::delay
    export function delay(time_ms: number): number{
        return 1;
    }
}
  

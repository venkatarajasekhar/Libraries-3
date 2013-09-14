/*
 * RA_Wiznet5100.h
 *
 *  Created on: Sep 11, 2013
 *      Author: Benjamin
 */

#ifndef RA_WIZNET5100_H_
#define RA_WIZNET5100_H_

#ifdef RA_STAR
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetDHCP.h>
#include <RA_Wifi.h>
#include <avr/wdt.h>

static EthernetServer NetServer(2000);
static byte NetMac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
static IPAddress NetIP(192,168,1,200);
const IPAddress PortalServer(198,171,134,6);
static EthernetClient NetClient;
#define PORTAL_TIMEOUT  10000

class RA_Wiznet5100 : public RA_Wifi
{
  public:
    RA_Wiznet5100();
    void Init();
    void ReceiveData();
    void ProcessEthernet();
    void Update();
    boolean PortalConnection;
    unsigned long PortalTimeOut;

  protected:
    size_t write(uint8_t c);
    size_t write(unsigned long n);
    size_t write(long n);
    size_t write(unsigned int n);
    size_t write(int n);
};
#endif  // RA_STAR
#endif /* RA_WIZNET5100_H_ */


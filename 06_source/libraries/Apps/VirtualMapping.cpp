#include "VirtualMapping.h"
#include "Arduino.h"
  
CVMapping::CVMapping(CPLSComms& plsComms):
    m_plsComms(plsComms)
{
  //do nothing
}
CVMapping::~CVMapping(){
  //do nothing
}
 void CVMapping::Init(void)
{
    m_plsComms.Init();
}

 void CVMapping::Run(void)
{
	//do nothing
}

 void CVMapping::Stop(void)
{
	//do nothing
}

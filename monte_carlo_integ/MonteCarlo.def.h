/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::done_2_closure : public SDAG::Closure {
            int total_counts;


      done_2_closure() {
        init();
      }
      done_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return total_counts;}
      void pup(PUP::er& __p) {
        __p | total_counts;
        packClosure(__p);
      }
      virtual ~done_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(done_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_MCCElement::MCIntegrate_2_closure : public SDAG::Closure {
            int Npersubdomain;
            float x_subdomain_min;
            float x_subdomain_max;
            float y_subdomain_min;
            float y_subdomain_max;


      MCIntegrate_2_closure() {
        init();
      }
      MCIntegrate_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return Npersubdomain;}
            float & getP1() { return x_subdomain_min;}
            float & getP2() { return x_subdomain_max;}
            float & getP3() { return y_subdomain_min;}
            float & getP4() { return y_subdomain_max;}
      void pup(PUP::er& __p) {
        __p | Npersubdomain;
        __p | x_subdomain_min;
        __p | x_subdomain_max;
        __p | y_subdomain_min;
        __p | y_subdomain_max;
        packClosure(__p);
      }
      virtual ~MCIntegrate_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(MCIntegrate_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done(int total_counts);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */
CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Main_CkArgMsg), CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  new (impl_obj_void) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void done(int total_counts);
 */
void CProxy_Main::done(int total_counts, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int total_counts
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|total_counts;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|total_counts;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_done_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_done_marshall2(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_done_marshall2(), impl_msg, &ckGetChareID(),0);
  }
}
void CkIndex_Main::_call_redn_wrapper_done_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int total_counts*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  PUP::detail::TemporaryObjectHolder<int> total_counts;
  implP|total_counts;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->done(std::move(total_counts.t));
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function
int CkIndex_Main::reg_done_marshall2() {
  int epidx = CkRegisterEp("done(int total_counts)",
      reinterpret_cast<CkCallFnPtr>(_call_done_marshall2), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_done_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_done_marshall2);

  return epidx;
}


// Redn wrapper registration function
int CkIndex_Main::reg_redn_wrapper_done_marshall2() {
  return CkRegisterEp("redn_wrapper_done(CkReductionMsg *impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_redn_wrapper_done_marshall2), CkMarshallMsg::__idx, __idx, 0);
}

void CkIndex_Main::_call_done_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int total_counts*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> total_counts;
  implP|total_counts;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->done(std::move(total_counts.t));
}
int CkIndex_Main::_callmarshall_done_marshall2(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: int total_counts*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> total_counts;
  implP|total_counts;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->done(std::move(total_counts.t));
  return implP.size();
}
void CkIndex_Main::_marshallmessagepup_done_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int total_counts*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> total_counts;
  implP|total_counts;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("total_counts");
  implDestP|total_counts;
}
PUPable_def(SINGLE_ARG(Closure_Main::done_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void done(int total_counts);
  idx_done_marshall2();
  idx_redn_wrapper_done_marshall2();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array MCCElement: ArrayElement{
MCCElement();
void MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max);
MCCElement(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_MCCElement::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_MCCElement::contribute(CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, userData, fragSize);
}

void CProxySection_MCCElement::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

template <typename T>
void CProxySection_MCCElement::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, userData, fragSize);
}

void CProxySection_MCCElement::contribute(CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, cb, userData, fragSize);
}

void CProxySection_MCCElement::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

template <typename T>
void CProxySection_MCCElement::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: MCCElement();
 */
void CProxyElement_MCCElement::insert(int onPE, const CkEntryOptions *impl_e_opts)
{ 
   void *impl_msg = CkAllocSysMsg(impl_e_opts);
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_MCCElement::idx_MCCElement_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max);
 */
void CProxyElement_MCCElement::MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|Npersubdomain;
    implP|x_subdomain_min;
    implP|x_subdomain_max;
    implP|y_subdomain_min;
    implP|y_subdomain_max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|Npersubdomain;
    implP|x_subdomain_min;
    implP|x_subdomain_max;
    implP|y_subdomain_min;
    implP|y_subdomain_max;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_MCCElement::idx_MCIntegrate_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: MCCElement(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: MCCElement();
 */
CkArrayID CProxy_MCCElement::ckNew(const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_MCCElement::idx_MCCElement_void(), opts);
  return gId;
}
void CProxy_MCCElement::ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_MCCElement::idx_MCCElement_void(), _ck_array_creation_cb, opts, impl_msg);
}
CkArrayID CProxy_MCCElement::ckNew(const int s1, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_MCCElement::idx_MCCElement_void(), opts);
  return gId;
}
void CProxy_MCCElement::ckNew(const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_MCCElement::idx_MCCElement_void(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
int CkIndex_MCCElement::reg_MCCElement_void() {
  int epidx = CkRegisterEp("MCCElement()",
      reinterpret_cast<CkCallFnPtr>(_call_MCCElement_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_MCCElement::_call_MCCElement_void(void* impl_msg, void* impl_obj_void)
{
  MCCElement* impl_obj = static_cast<MCCElement*>(impl_obj_void);
  new (impl_obj_void) MCCElement();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max);
 */
void CProxy_MCCElement::MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|Npersubdomain;
    implP|x_subdomain_min;
    implP|x_subdomain_max;
    implP|y_subdomain_min;
    implP|y_subdomain_max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|Npersubdomain;
    implP|x_subdomain_min;
    implP|x_subdomain_max;
    implP|y_subdomain_min;
    implP|y_subdomain_max;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_MCCElement::idx_MCIntegrate_marshall2(),0);
}

// Entry point registration function
int CkIndex_MCCElement::reg_MCIntegrate_marshall2() {
  int epidx = CkRegisterEp("MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max)",
      reinterpret_cast<CkCallFnPtr>(_call_MCIntegrate_marshall2), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_MCIntegrate_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_MCIntegrate_marshall2);

  return epidx;
}

void CkIndex_MCCElement::_call_MCIntegrate_marshall2(void* impl_msg, void* impl_obj_void)
{
  MCCElement* impl_obj = static_cast<MCCElement*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> Npersubdomain;
  implP|Npersubdomain;
  PUP::detail::TemporaryObjectHolder<float> x_subdomain_min;
  implP|x_subdomain_min;
  PUP::detail::TemporaryObjectHolder<float> x_subdomain_max;
  implP|x_subdomain_max;
  PUP::detail::TemporaryObjectHolder<float> y_subdomain_min;
  implP|y_subdomain_min;
  PUP::detail::TemporaryObjectHolder<float> y_subdomain_max;
  implP|y_subdomain_max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->MCIntegrate(std::move(Npersubdomain.t), std::move(x_subdomain_min.t), std::move(x_subdomain_max.t), std::move(y_subdomain_min.t), std::move(y_subdomain_max.t));
}
int CkIndex_MCCElement::_callmarshall_MCIntegrate_marshall2(char* impl_buf, void* impl_obj_void) {
  MCCElement* impl_obj = static_cast<MCCElement*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> Npersubdomain;
  implP|Npersubdomain;
  PUP::detail::TemporaryObjectHolder<float> x_subdomain_min;
  implP|x_subdomain_min;
  PUP::detail::TemporaryObjectHolder<float> x_subdomain_max;
  implP|x_subdomain_max;
  PUP::detail::TemporaryObjectHolder<float> y_subdomain_min;
  implP|y_subdomain_min;
  PUP::detail::TemporaryObjectHolder<float> y_subdomain_max;
  implP|y_subdomain_max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->MCIntegrate(std::move(Npersubdomain.t), std::move(x_subdomain_min.t), std::move(x_subdomain_max.t), std::move(y_subdomain_min.t), std::move(y_subdomain_max.t));
  return implP.size();
}
void CkIndex_MCCElement::_marshallmessagepup_MCIntegrate_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> Npersubdomain;
  implP|Npersubdomain;
  PUP::detail::TemporaryObjectHolder<float> x_subdomain_min;
  implP|x_subdomain_min;
  PUP::detail::TemporaryObjectHolder<float> x_subdomain_max;
  implP|x_subdomain_max;
  PUP::detail::TemporaryObjectHolder<float> y_subdomain_min;
  implP|y_subdomain_min;
  PUP::detail::TemporaryObjectHolder<float> y_subdomain_max;
  implP|y_subdomain_max;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("Npersubdomain");
  implDestP|Npersubdomain;
  if (implDestP.hasComments()) implDestP.comment("x_subdomain_min");
  implDestP|x_subdomain_min;
  if (implDestP.hasComments()) implDestP.comment("x_subdomain_max");
  implDestP|x_subdomain_max;
  if (implDestP.hasComments()) implDestP.comment("y_subdomain_min");
  implDestP|y_subdomain_min;
  if (implDestP.hasComments()) implDestP.comment("y_subdomain_max");
  implDestP|y_subdomain_max;
}
PUPable_def(SINGLE_ARG(Closure_MCCElement::MCIntegrate_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: MCCElement(CkMigrateMessage* impl_msg);
 */

// Entry point registration function
int CkIndex_MCCElement::reg_MCCElement_CkMigrateMessage() {
  int epidx = CkRegisterEp("MCCElement(CkMigrateMessage* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_MCCElement_CkMigrateMessage), 0, __idx, 0);
  return epidx;
}

void CkIndex_MCCElement::_call_MCCElement_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<MCCElement> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: MCCElement();
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max);
 */
void CProxySection_MCCElement::MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|Npersubdomain;
    implP|x_subdomain_min;
    implP|x_subdomain_max;
    implP|y_subdomain_min;
    implP|y_subdomain_max;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|Npersubdomain;
    implP|x_subdomain_min;
    implP|x_subdomain_max;
    implP|y_subdomain_min;
    implP|y_subdomain_max;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_MCCElement::idx_MCIntegrate_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: MCCElement(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_MCCElement::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterArrayDimensions(__idx, 1);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: MCCElement();
  idx_MCCElement_void();
  CkRegisterDefaultCtor(__idx, idx_MCCElement_void());

  // REG: void MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max);
  idx_MCIntegrate_marshall2();

  // REG: MCCElement(CkMigrateMessage* impl_msg);
  idx_MCCElement_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_MCCElement_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerMonteCarlo(void)
{
  static int _done = 0; if(_done) return; _done = 1;
/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done(int total_counts);
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array MCCElement: ArrayElement{
MCCElement();
void MCIntegrate(int Npersubdomain, float x_subdomain_min, float x_subdomain_max, float y_subdomain_min, float y_subdomain_max);
MCCElement(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_MCCElement::__register("MCCElement", sizeof(MCCElement));

}
extern "C" void CkRegisterMainModule(void) {
  _registerMonteCarlo();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main>(dynamic_cast<Main*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_MCCElement::virtual_pup(PUP::er &p) {
    recursive_pup<MCCElement>(dynamic_cast<MCCElement*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */

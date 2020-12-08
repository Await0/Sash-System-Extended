// 1. Find
bool CHARACTER::SashIsSameGrade(long lGrade)


// 2. Change with
#ifdef __SASH_SYSTEM_EXTENDED__
bool CHARACTER::SashIsSameGrade(long lGrade, long lAbs)
#else
bool CHARACTER::SashIsSameGrade(long lGrade)
#endif


// 3. Inside the function CHARACTER::SashIsSameGrade find
bool bReturn = (pkItemMaterial[0]->GetValue(SASH_GRADE_VALUE_FIELD) == lGrade ? true : false);


// 4. Change with
#ifdef __SASH_SYSTEM_EXTENDED__
	bool bReturn = ((pkItemMaterial[0]->GetValue(SASH_GRADE_VALUE_FIELD) == lGrade) && (pkItemMaterial[0]->GetSocket(SASH_ABSORPTION_SOCKET) == lAbs) ? true : false);
#else
	bool bReturn = (pkItemMaterial[0]->GetValue(SASH_GRADE_VALUE_FIELD) == lGrade ? true : false);
#endif


// 5. Find inside CHARACTER::GetSashCombineResult
				dwItemVnum = pkItemMaterial[0]->GetOriginalVnum();
				dwMinAbs = pkItemMaterial[0]->GetSocket(SASH_ABSORPTION_SOCKET);
				DWORD dwMaxAbsCalc = (dwMinAbs + SASH_GRADE_4_ABS_RANGE > SASH_GRADE_4_ABS_MAX ? SASH_GRADE_4_ABS_MAX : (dwMinAbs + SASH_GRADE_4_ABS_RANGE));
				dwMaxAbs = dwMaxAbsCalc;


// 6. Change with
#ifdef __SASH_SYSTEM_EXTENDED__
				dwItemVnum = pkItemMaterial[0]->GetOriginalVnum();
				dwMinAbs = (pkItemMaterial[0]->GetSocket(SASH_ABSORPTION_SOCKET)) + 1;
				dwMaxAbs = dwMinAbs;
#else
				dwItemVnum = pkItemMaterial[0]->GetOriginalVnum();
				dwMinAbs = pkItemMaterial[0]->GetSocket(SASH_ABSORPTION_SOCKET);
				DWORD dwMaxAbsCalc = (dwMinAbs + SASH_GRADE_4_ABS_RANGE > SASH_GRADE_4_ABS_MAX ? SASH_GRADE_4_ABS_MAX : (dwMinAbs + SASH_GRADE_4_ABS_RANGE));
				dwMaxAbs = dwMaxAbsCalc;
#endif


// 7. Find
							dwMinAbs = SASH_GRADE_4_ABS_MIN;
							dwMaxAbs = SASH_GRADE_4_ABS_MAX_COMB;
							
// 8. Change with
#ifdef __SASH_SYSTEM_EXTENDED__
							dwMinAbs = SASH_GRADE_3_ABS + 1;
							dwMaxAbs = SASH_GRADE_3_ABS + 1;
#else
							dwMinAbs = SASH_GRADE_4_ABS_MIN;
							dwMaxAbs = SASH_GRADE_4_ABS_MAX_COMB;
#endif


// 9. Find
else if ((m_bSashCombination) && (bPos == 1) && (!SashIsSameGrade(pkItem->GetValue(SASH_GRADE_VALUE_FIELD))))


// 10. Change with
#ifdef __SASH_SYSTEM_EXTENDED__
	else if ((m_bSashCombination) && (bPos == 1) && (!SashIsSameGrade(pkItem->GetValue(SASH_GRADE_VALUE_FIELD),pkItem->GetSocket(SASH_ABSORPTION_SOCKET))))
#else
	else if ((m_bSashCombination) && (bPos == 1) && (!SashIsSameGrade(pkItem->GetValue(SASH_GRADE_VALUE_FIELD))))
#endif

// 11. Find inside CHARACTER::RefineSashMaterials

		long lVal = pkItemMaterial[0]->GetValue(SASH_GRADE_VALUE_FIELD);
		
// 12. Add
#ifdef __SASH_SYSTEM_EXTENDED__
		DWORD currAbs = dwMinAbs;
#endif

// 13. Find

iSuccessChance = SASH_COMBINE_GRADE_4;

// 14. Change with

#ifdef __SASH_SYSTEM_EXTENDED__
					if (currAbs >= 11 && currAbs < 19)
						iSuccessChance = 100;
					else if (currAbs == 19 || currAbs == 20)
						iSuccessChance = 85;
					else if (currAbs == 21)
						iSuccessChance = 75;
					else if (currAbs == 22 || currAbs == 23)
						iSuccessChance = 65;
					else if (currAbs == 24)
						iSuccessChance = 50;
					else if (currAbs == 25)
						iSuccessChance = SASH_COMBINE_GRADE_4; // 30
#else
					iSuccessChance = SASH_COMBINE_GRADE_4;
#endif

// 15. Find

			DWORD dwAbs = (dwMinAbs == dwMaxAbs ? dwMinAbs : number(dwMinAbs + 1, dwMaxAbs));


// 16. Change with

#ifdef __SASH_SYSTEM_EXTENDED__
			DWORD dwAbs = dwMinAbs++;
#else
			DWORD dwAbs = (dwMinAbs == dwMaxAbs ? dwMinAbs : number(dwMinAbs + 1, dwMaxAbs));
#endif


// 17. Find
			if (lVal == 4)
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("New absorption rate: %d%"), dwAbs);
			else
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Success."));


// 18. Change with
#ifdef __SASH_SYSTEM_EXTENDED__
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Success."));
#else
			if (lVal == 4)
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("New absorption rate: %d%"), dwAbs);
			else
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Success."));
#endif
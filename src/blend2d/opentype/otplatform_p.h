// This file is part of Blend2D project <https://blend2d.com>
//
// See blend2d.h or LICENSE.md for license and copyright information
// SPDX-License-Identifier: Zlib

#ifndef BLEND2D_OPENTYPE_OTPLATFORM_P_H_INCLUDED
#define BLEND2D_OPENTYPE_OTPLATFORM_P_H_INCLUDED

#include "../opentype/otcore_p.h"

//! \cond INTERNAL
//! \addtogroup blend2d_opentype_impl
//! \{

//! Platform support for TrueType and OpenType fonts.
//!
//! Mostly required by 'cmap' and 'name' tables. This namespace provides all the constants necessary to read the
//! right information from these tables.
namespace bl::OpenType::Platform {

//! Platform id.
enum PlatformId : uint32_t {
  //! Unicode platform.
  kPlatformUnicode = 0,
  //! Mac platform (deprecated).
  kPlatformMac = 1,
  //! ISO platform (deprecated).
  kPlatformISO = 2,
  //! Windows platform.
  kPlatformWindows = 3,
  //! Custom ('name' table only).
  kPlatformCustom = 4
};

//! Encoding id specific to `kPlatformUnicode` platform-id.
enum UnicodeEncodingId : uint32_t {
  //! Unicode V1.0.
  kUnicodeEncodingV1_0 = 0,
  //! Unicode V1.1.
  kUnicodeEncodingV1_1 = 1,
  //! Deprecated encoding id.
  kUnicodeEncodingISO = 2,
  //! Unicode V2.0 (BMP).
  kUnicodeEncodingV2_0 = 3,
  //! Unicode V3.1 (non-BMP characters).
  kUnicodeEncodingV3_1 = 4,
  //! Unicode Variation Sequences.
  kUnicodeEncodingVariation = 5,
  //! Full Unicode coverage.
  kUnicodeEncodingFull = 6
};

//! Encoding id specific to `kPlatformMac` platform-id (deprecated).
//!
//! \note Apple says that this id is compatible with QuickDraw script code and the use of `kPlatformMac` is currently
//! discouraged. Blend2D doesn't try to interpret this encoding and the enumeration is here just for reference.
enum MacEncodingId : uint32_t {
  kMacEncodingRoman = 0,
  kMacEncodingJapanese = 1,
  kMacEncodingTraditionalChinese = 2,
  kMacEncodingKorean = 3,
  kMacEncodingArabic = 4,
  kMacEncodingHebrew = 5,
  kMacEncodingGreek = 6,
  kMacEncodingRussian = 7,
  kMacEncodingRSymbol = 8,
  kMacEncodingDevanagari = 9,
  kMacEncodingGurmukhi = 10,
  kMacEncodingGujarati = 11,
  kMacEncodingOriya = 12,
  kMacEncodingBengali = 13,
  kMacEncodingTamil = 14,
  kMacEncodingTelugu = 15,
  kMacEncodingKannada = 16,
  kMacEncodingMalayalam = 17,
  kMacEncodingSinhalese = 18,
  kMacEncodingBurmese = 19,
  kMacEncodingKhmer = 20,
  kMacEncodingThai = 21,
  kMacEncodingLaotian = 22,
  kMacEncodingGeorgian = 23,
  kMacEncodingArmenian = 24,
  kMacEncodingSimplifiedChinese = 25,
  kMacEncodingTibetan = 26,
  kMacEncodingMongolian = 27,
  kMacEncodingGeez = 28,
  kMacEncodingSlavic = 29,
  kMacEncodingVietnamese = 30,
  kMacEncodingSindhi = 31,
  kMacEncodingUninterpreted = 32
};

enum MacLanguageId : uint32_t {
  kMacLanguageEnglish = 0,
  kMacLanguageFrench = 1,
  kMacLanguageGerman = 2,
  kMacLanguageItalian = 3,
  kMacLanguageDutch = 4,
  kMacLanguageSwedish = 5,
  kMacLanguageSpanish = 6,
  kMacLanguageDanish = 7,
  kMacLanguagePortuguese = 8,
  kMacLanguageNorwegian = 9,
  kMacLanguageHebrew = 10,
  kMacLanguageJapanese = 11,
  kMacLanguageArabic = 12,
  kMacLanguageFinnish = 13,
  kMacLanguageGreek = 14,
  kMacLanguageIcelandic = 15,
  kMacLanguageMaltese = 16,
  kMacLanguageTurkish = 17,
  kMacLanguageCroatian = 18,
  kMacLanguageTraditionalChinese = 19,
  kMacLanguageUrdu = 20,
  kMacLanguageHindi = 21,
  kMacLanguageThai = 22,
  kMacLanguageKorean = 23,
  kMacLanguageLithuanian = 24,
  kMacLanguagePolish = 25,
  kMacLanguageHungarian = 26,
  kMacLanguageEstonian = 27,
  kMacLanguageLatvian = 28,
  kMacLanguageSami = 29,
  kMacLanguageFaroese = 30,
  kMacLanguageFarsi = 31,
  kMacLanguageRussian = 32,
  kMacLanguageSimplifiedChinese = 33,
  kMacLanguageFlemish = 34,
  kMacLanguageIrish = 35,
  kMacLanguageAlbanian = 36,
  kMacLanguageRomanian = 37,
  kMacLanguageCzech = 38,
  kMacLanguageSlovak = 39,
  kMacLanguageSlovenian = 40,
  kMacLanguageYiddish = 41,
  kMacLanguageSerbian = 42,
  kMacLanguageMacedonian = 43,
  kMacLanguageBulgarian = 44,
  kMacLanguageUkrainian = 45,
  kMacLanguageByelorussian = 46,
  kMacLanguageUzbek = 47,
  kMacLanguageKazakh = 48,
  kMacLanguageAzerbaijani_Cyrillic = 49,
  kMacLanguageAzerbaijani_Arabic = 50,
  kMacLanguageArmenian = 51,
  kMacLanguageGeorgian = 52,
  kMacLanguageMoldavian = 53,
  kMacLanguageKirghiz = 54,
  kMacLanguageTajiki = 55,
  kMacLanguageTurkmen = 56,
  kMacLanguageMongolian_Mongolian = 57,
  kMacLanguageMongolian_Cyrillic = 58,
  kMacLanguagePashto = 59,
  kMacLanguageKurdish = 60,
  kMacLanguageKashmiri = 61,
  kMacLanguageSindhi = 62,
  kMacLanguageTibetan = 63,
  kMacLanguageNepali = 64,
  kMacLanguageSanskrit = 65,
  kMacLanguageMarathi = 66,
  kMacLanguageBengali = 67,
  kMacLanguageAssamese = 68,
  kMacLanguageGujarati = 69,
  kMacLanguagePunjabi = 70,
  kMacLanguageOriya = 71,
  kMacLanguageMalayalam = 72,
  kMacLanguageKannada = 73,
  kMacLanguageTamil = 74,
  kMacLanguageTelugu = 75,
  kMacLanguageSinhalese = 76,
  kMacLanguageBurmese = 77,
  kMacLanguageKhmer = 78,
  kMacLanguageLao = 79,
  kMacLanguageVietnamese = 80,
  kMacLanguageIndonesian = 81,
  kMacLanguageTagalog = 82,
  kMacLanguageMalay_Roman = 83,
  kMacLanguageMalay_Arabic = 84,
  kMacLanguageAmharic = 85,
  kMacLanguageTigrinya = 86,
  kMacLanguageGalla = 87,
  kMacLanguageSomali = 88,
  kMacLanguageSwahili = 89,
  kMacLanguageKinyarwandaRuanda = 90,
  kMacLanguageRundi = 91,
  kMacLanguageNyanjaChewa = 92,
  kMacLanguageMalagasy = 93,
  kMacLanguageEsperanto = 94,
  kMacLanguageWelsh = 128,
  kMacLanguageBasque = 129,
  kMacLanguageCatalan = 130,
  kMacLanguageLatin = 131,
  kMacLanguageQuechua = 132,
  kMacLanguageGuarani = 133,
  kMacLanguageAymara = 134,
  kMacLanguageTatar = 135,
  kMacLanguageUighur = 136,
  kMacLanguageDzongkha = 137,
  kMacLanguageJavanese = 138,
  kMacLanguageSundanese = 139,
  kMacLanguageGalician = 140,
  kMacLanguageAfrikaans = 141,
  kMacLanguageBreton = 142,
  kMacLanguageInuktitut = 143,
  kMacLanguageScottish = 144,
  kMacLanguageManx = 145,
  kMacLanguageIrish_GaelicDot = 146,
  kMacLanguageTongan = 147,
  kMacLanguageGreek_Polytonic = 148,
  kMacLanguageGreenlandic = 149,
  kMacLanguageAzerbaijani_Roman = 150
};

//! Encoding id specific to `kPlatformWindows` platform-id.
enum WindowsEncodingId : uint32_t {
  kWindowsEncodingSymbol = 0,
  kWindowsEncodingUCS2 = 1,
  kWindowsEncodingShiftJIS = 2,
  kWindowsEncodingSimplifiedChinese = 3,
  kWindowsEncodingTraditionalChinese = 4,
  kWindowsEncodingWansung = 5,
  kWindowsEncodingJohab = 6,
  kWindowsEncodingUCS4 = 10
};

//! Primary language of Windows platform.
//!
//! \note Don't confuse with \ref WindowsLocaleId, which is the right enumeration used by `languageId` records in 'cmap'
//! and 'name' tables, see \ref WindowsLocaleId.
enum WindowsLanguageId : uint32_t {
  kWindowsLanguageNeutral                = 0x00,
  kWindowsLanguageAfrikaans              = 0x36,
  kWindowsLanguageAlbanian               = 0x1C,
  kWindowsLanguageAlsatian               = 0x84,
  kWindowsLanguageAmharic                = 0x5E,
  kWindowsLanguageArabic                 = 0x01,
  kWindowsLanguageArmenian               = 0x2B,
  kWindowsLanguageAssamese               = 0x4D,
  kWindowsLanguageAzeri                  = 0x2C,
  kWindowsLanguageBashkir                = 0x6D,
  kWindowsLanguageBasque                 = 0x2D,
  kWindowsLanguageBelarusian             = 0x23,
  kWindowsLanguageBengali                = 0x45,
  kWindowsLanguageBosnian                = 0x1A,
  kWindowsLanguageBreton                 = 0x7E,
  kWindowsLanguageBulgarian              = 0x02,
  kWindowsLanguageCatalan                = 0x03,
  kWindowsLanguageChinese                = 0x04,
  kWindowsLanguageCorsican               = 0x83,
  kWindowsLanguageCroatian               = 0x1A,
  kWindowsLanguageCzech                  = 0x05,
  kWindowsLanguageDanish                 = 0x06,
  kWindowsLanguageDari                   = 0x8C,
  kWindowsLanguageDivehi                 = 0x65,
  kWindowsLanguageDutch                  = 0x13,
  kWindowsLanguageEnglish                = 0x09,
  kWindowsLanguageEstonian               = 0x25,
  kWindowsLanguageFaroese                = 0x38,
  kWindowsLanguageFilipino               = 0x64,
  kWindowsLanguageFinnish                = 0x0B,
  kWindowsLanguageFrench                 = 0x0C,
  kWindowsLanguageFrisian                = 0x62,
  kWindowsLanguageGalician               = 0x56,
  kWindowsLanguageGeorgian               = 0x37,
  kWindowsLanguageGerman                 = 0x07,
  kWindowsLanguageGreek                  = 0x08,
  kWindowsLanguageGreenlandic            = 0x6F,
  kWindowsLanguageGujarati               = 0x47,
  kWindowsLanguageHausa                  = 0x68,
  kWindowsLanguageHebrew                 = 0x0D,
  kWindowsLanguageHindi                  = 0x39,
  kWindowsLanguageHungarian              = 0x0E,
  kWindowsLanguageIcelandic              = 0x0F,
  kWindowsLanguageIgbo                   = 0x70,
  kWindowsLanguageIndonesian             = 0x21,
  kWindowsLanguageInuktitut              = 0x5D,
  kWindowsLanguageIrish                  = 0x3C,
  kWindowsLanguageIsiXhosa               = 0x34,
  kWindowsLanguageIsiZulu                = 0x35,
  kWindowsLanguageItalian                = 0x10,
  kWindowsLanguageJapanese               = 0x11,
  kWindowsLanguageKannada                = 0x4B,
  kWindowsLanguageKazakh                 = 0x3F,
  kWindowsLanguageKhmer                  = 0x53,
  kWindowsLanguageIche                   = 0x86,
  kWindowsLanguageKinyarwanda            = 0x87,
  kWindowsLanguageKiswahili              = 0x41,
  kWindowsLanguageKonkani                = 0x57,
  kWindowsLanguageKorean                 = 0x12,
  kWindowsLanguageKyrgyz                 = 0x40,
  kWindowsLanguageLao                    = 0x54,
  kWindowsLanguageLatvian                = 0x26,
  kWindowsLanguageLithuanian             = 0x27,
  kWindowsLanguageLowerSorbian           = 0x2E,
  kWindowsLanguageLuxembourgish          = 0x6E,
  kWindowsLanguageMacedonian             = 0x2F,
  kWindowsLanguageMalay                  = 0x3E,
  kWindowsLanguageMalayalam              = 0x4C,
  kWindowsLanguageMaltese                = 0x3A,
  kWindowsLanguageMaori                  = 0x81,
  kWindowsLanguageMapudungun             = 0x7A,
  kWindowsLanguageMarathi                = 0x4E,
  kWindowsLanguageMohawk                 = 0x7C,
  kWindowsLanguageMongolian              = 0x50,
  kWindowsLanguageNepali                 = 0x61,
  kWindowsLanguageNorwegian              = 0x14,
  kWindowsLanguageOccitan                = 0x82,
  kWindowsLanguageOdia                   = 0x48,
  kWindowsLanguagePashto                 = 0x63,
  kWindowsLanguagePolish                 = 0x15,
  kWindowsLanguagePortuguese             = 0x16,
  kWindowsLanguagePunjabi                = 0x46,
  kWindowsLanguageQuechua                = 0x6B,
  kWindowsLanguageRomanian               = 0x18,
  kWindowsLanguageRomansh                = 0x17,
  kWindowsLanguageRussian                = 0x19,
  kWindowsLanguageSami                   = 0x3B,
  kWindowsLanguageSanskrit               = 0x4F,
  kWindowsLanguageSerbian                = 0x1A,
  kWindowsLanguageSesothoSaLeboa         = 0x6C,
  kWindowsLanguageSetswana               = 0x32,
  kWindowsLanguageSinhala                = 0x5B,
  kWindowsLanguageSlovak                 = 0x1B,
  kWindowsLanguageSlovenian              = 0x24,
  kWindowsLanguageSpanish                = 0x0A,
  kWindowsLanguageSweden                 = 0x1D,
  kWindowsLanguageSwedish                = 0x1D,
  kWindowsLanguageSyriac                 = 0x5A,
  kWindowsLanguageTajik                  = 0x28,
  kWindowsLanguageTamazight              = 0x5F,
  kWindowsLanguageTamil                  = 0x49,
  kWindowsLanguageTatar                  = 0x44,
  kWindowsLanguageTelugu                 = 0x4A,
  kWindowsLanguageThai                   = 0x1E,
  kWindowsLanguageTibetan                = 0x51,
  kWindowsLanguageTurkish                = 0x1F,
  kWindowsLanguageTurkmen                = 0x42,
  kWindowsLanguageUighur                 = 0x80,
  kWindowsLanguageUkrainian              = 0x22,
  kWindowsLanguageUpperSorbian           = 0x2E,
  kWindowsLanguageUrdu                   = 0x20,
  kWindowsLanguageUzbek                  = 0x43,
  kWindowsLanguageVietnamese             = 0x2A,
  kWindowsLanguageWelsh                  = 0x52,
  kWindowsLanguageWolof                  = 0x88,
  kWindowsLanguageYakut                  = 0x85,
  kWindowsLanguageYi                     = 0x78,
  kWindowsLanguageYoruba                 = 0x6A
};

//! Windows locale is a combination of a primary language (WindowsLanguageId) and geographical location. These IDs
//! are used by `languageId` member in records stored in 'cmap' and 'name' tables.
//!
//! \note We omit country in cases where there is only a single country.
enum WindowsLocaleId : uint32_t {
  kWindowsLocaleAfrikaans                = 0x0436,
  kWindowsLocaleAlbanian                 = 0x041C,
  kWindowsLocaleAlsatian                 = 0x0484,
  kWindowsLocaleAmharic                  = 0x045E,
  kWindowsLocaleArabic_Algeria           = 0x1401,
  kWindowsLocaleArabic_Bahrain           = 0x3C01,
  kWindowsLocaleArabic_Egypt             = 0x0C01,
  kWindowsLocaleArabic_Iraq              = 0x0801,
  kWindowsLocaleArabic_Jordan            = 0x2C01,
  kWindowsLocaleArabic_Kuwait            = 0x3401,
  kWindowsLocaleArabic_Lebanon           = 0x3001,
  kWindowsLocaleArabic_Libya             = 0x1001,
  kWindowsLocaleArabic_Morocco           = 0x1801,
  kWindowsLocaleArabic_Oman              = 0x2001,
  kWindowsLocaleArabic_Qatar             = 0x4001,
  kWindowsLocaleArabic_SaudiArabia       = 0x0401,
  kWindowsLocaleArabic_Syria             = 0x2801,
  kWindowsLocaleArabic_Tunisia           = 0x1C01,
  kWindowsLocaleArabic_UAE               = 0x3801,
  kWindowsLocaleArabic_Yemen             = 0x2401,
  kWindowsLocaleArmenian                 = 0x042B,
  kWindowsLocaleAssamese                 = 0x044D,
  kWindowsLocaleAzeri_Cyrillic           = 0x082C,
  kWindowsLocaleAzeri_Latin              = 0x042C,
  kWindowsLocaleBashkir                  = 0x046D,
  kWindowsLocaleBasque                   = 0x042D,
  kWindowsLocaleBelarusian               = 0x0423,
  kWindowsLocaleBengali_Bangladesh       = 0x0845,
  kWindowsLocaleBengali_India            = 0x0445,
  kWindowsLocaleBosnian_Cyrillic         = 0x201A,
  kWindowsLocaleBosnian_Latin            = 0x141A,
  kWindowsLocaleBreton                   = 0x047E,
  kWindowsLocaleBulgarian                = 0x0402,
  kWindowsLocaleCatalan                  = 0x0403,
  kWindowsLocaleChinese_HongKong         = 0x0C04,
  kWindowsLocaleChinese_Macao            = 0x1404,
  kWindowsLocaleChinese_Simplified       = 0x0804,
  kWindowsLocaleChinese_Singapore        = 0x1004,
  kWindowsLocaleChinese_Taiwan           = 0x0404,
  kWindowsLocaleCorsican                 = 0x0483,
  kWindowsLocaleCroatian                 = 0x041A,
  kWindowsLocaleCroatian_Latin           = 0x101A,
  kWindowsLocaleCzech                    = 0x0405,
  kWindowsLocaleDanish                   = 0x0406,
  kWindowsLocaleDari                     = 0x048C,
  kWindowsLocaleDivehi                   = 0x0465,
  kWindowsLocaleDutch_Belgium            = 0x0813,
  kWindowsLocaleDutch_Netherlands        = 0x0413,
  kWindowsLocaleEnglish_Australia        = 0x0C09,
  kWindowsLocaleEnglish_Belize           = 0x2809,
  kWindowsLocaleEnglish_Canada           = 0x1009,
  kWindowsLocaleEnglish_Caribbean        = 0x2409,
  kWindowsLocaleEnglish_India            = 0x4009,
  kWindowsLocaleEnglish_Ireland          = 0x1809,
  kWindowsLocaleEnglish_Jamaica          = 0x2009,
  kWindowsLocaleEnglish_Malaysia         = 0x4409,
  kWindowsLocaleEnglish_NewZealand       = 0x1409,
  kWindowsLocaleEnglish_Philippines      = 0x3409,
  kWindowsLocaleEnglish_Singapore        = 0x4809,
  kWindowsLocaleEnglish_SouthAfrica      = 0x1C09,
  kWindowsLocaleEnglish_TrinidadAndTobago= 0x2C09,
  kWindowsLocaleEnglish_UK               = 0x0809,
  kWindowsLocaleEnglish_US               = 0x0409,
  kWindowsLocaleEnglish_Zimbabwe         = 0x3009,
  kWindowsLocaleEstonian                 = 0x0425,
  kWindowsLocaleFaroese                  = 0x0438,
  kWindowsLocaleFilipino                 = 0x0464,
  kWindowsLocaleFinnish                  = 0x040B,
  kWindowsLocaleFrench                   = 0x040C,
  kWindowsLocaleFrench_Belgium           = 0x080C,
  kWindowsLocaleFrench_Canada            = 0x0C0C,
  kWindowsLocaleFrench_Luxembourg        = 0x140C,
  kWindowsLocaleFrench_Monaco            = 0x180C,
  kWindowsLocaleFrench_Switzerland       = 0x100C,
  kWindowsLocaleFrisian                  = 0x0462,
  kWindowsLocaleGalician                 = 0x0456,
  kWindowsLocaleGeorgian                 = 0x0437,
  kWindowsLocaleGerman                   = 0x0407,
  kWindowsLocaleGerman_Austria           = 0x0C07,
  kWindowsLocaleGerman_Liechtenstein     = 0x1407,
  kWindowsLocaleGerman_Luxembourg        = 0x1007,
  kWindowsLocaleGerman_Switzerland       = 0x0807,
  kWindowsLocaleGreek                    = 0x0408,
  kWindowsLocaleGreenlandic              = 0x046F,
  kWindowsLocaleGujarati                 = 0x0447,
  kWindowsLocaleHausa                    = 0x0468,
  kWindowsLocaleHebrew                   = 0x040D,
  kWindowsLocaleHindi                    = 0x0439,
  kWindowsLocaleHungarian                = 0x040E,
  kWindowsLocaleIcelandic                = 0x040F,
  kWindowsLocaleIgbo                     = 0x0470,
  kWindowsLocaleIndonesian               = 0x0421,
  kWindowsLocaleInuktitut                = 0x045D,
  kWindowsLocaleInuktitut_Latin          = 0x085D,
  kWindowsLocaleIrish                    = 0x083C,
  kWindowsLocaleIsiXhosa                 = 0x0434,
  kWindowsLocaleIsiZulu                  = 0x0435,
  kWindowsLocaleItalian                  = 0x0410,
  kWindowsLocaleItalian_Switzerland      = 0x0810,
  kWindowsLocaleJapanese                 = 0x0411,
  kWindowsLocaleKannada                  = 0x044B,
  kWindowsLocaleKazakh                   = 0x043F,
  kWindowsLocaleKhmer                    = 0x0453,
  kWindowsLocaleIche                     = 0x0486,
  kWindowsLocaleKinyarwanda              = 0x0487,
  kWindowsLocaleKiswahili                = 0x0441,
  kWindowsLocaleKonkani                  = 0x0457,
  kWindowsLocaleKorean                   = 0x0412,
  kWindowsLocaleKyrgyz                   = 0x0440,
  kWindowsLocaleLao                      = 0x0454,
  kWindowsLocaleLatvian                  = 0x0426,
  kWindowsLocaleLithuanian               = 0x0427,
  kWindowsLocaleLowerSorbian             = 0x082E,
  kWindowsLocaleLuxembourgish            = 0x046E,
  kWindowsLocaleMacedonian               = 0x042F,
  kWindowsLocaleMalay                    = 0x043E,
  kWindowsLocaleMalay_BruneiDarussalam   = 0x083E,
  kWindowsLocaleMalayalam                = 0x044C,
  kWindowsLocaleMaltese                  = 0x043A,
  kWindowsLocaleMaori                    = 0x0481,
  kWindowsLocaleMapudungun               = 0x047A,
  kWindowsLocaleMarathi                  = 0x044E,
  kWindowsLocaleMohawk                   = 0x047C,
  kWindowsLocaleMongolian_Cyrillic       = 0x0450,
  kWindowsLocaleMongolian_PRC            = 0x0850,
  kWindowsLocaleNepali                   = 0x0461,
  kWindowsLocaleNorwegian_Bokmal         = 0x0414,
  kWindowsLocaleNorwegian_Nynorsk        = 0x0814,
  kWindowsLocaleOccitan                  = 0x0482,
  kWindowsLocaleOdia                     = 0x0448,
  kWindowsLocalePashto                   = 0x0463,
  kWindowsLocalePolish                   = 0x0415,
  kWindowsLocalePortuguese_Portugal      = 0x0816,
  kWindowsLocalePortuguese_Brazil        = 0x0416,
  kWindowsLocalePunjabi                  = 0x0446,
  kWindowsLocaleQuechua_Bolivia          = 0x046B,
  kWindowsLocaleQuechua_Ecuador          = 0x086B,
  kWindowsLocaleQuechua_Peru             = 0x0C6B,
  kWindowsLocaleRomanian                 = 0x0418,
  kWindowsLocaleRomansh                  = 0x0417,
  kWindowsLocaleRussian                  = 0x0419,
  kWindowsLocaleSami_InariFinland        = 0x243B,
  kWindowsLocaleSami_LuleNorway          = 0x103B,
  kWindowsLocaleSami_LuleSweden          = 0x143B,
  kWindowsLocaleSami_NorthernFinland     = 0x0C3B,
  kWindowsLocaleSami_NorthernNorway      = 0x043B,
  kWindowsLocaleSami_NorthernSweden      = 0x083B,
  kWindowsLocaleSami_SkoltFinland        = 0x203B,
  kWindowsLocaleSami_SouthernNorway      = 0x183B,
  kWindowsLocaleSami_SouthernSweden      = 0x1C3B,
  kWindowsLocaleSanskrit                 = 0x044F,
  kWindowsLocaleSerbian_Cyrillic_BH      = 0x1C1A,
  kWindowsLocaleSerbian_Cyrillic_Serbia  = 0x0C1A,
  kWindowsLocaleSerbian_Latin_BH         = 0x181A,
  kWindowsLocaleSerbian_Latin_Serbia     = 0x081A,
  kWindowsLocaleSesothoSaLeboa           = 0x046C,
  kWindowsLocaleSetswana                 = 0x0432,
  kWindowsLocaleSinhala                  = 0x045B,
  kWindowsLocaleSlovak                   = 0x041B,
  kWindowsLocaleSlovenian                = 0x0424,
  kWindowsLocaleSpanish                  = 0x040A,
  kWindowsLocaleSpanish_Argentina        = 0x2C0A,
  kWindowsLocaleSpanish_Bolivia          = 0x400A,
  kWindowsLocaleSpanish_Chile            = 0x340A,
  kWindowsLocaleSpanish_Colombia         = 0x240A,
  kWindowsLocaleSpanish_CostaRica        = 0x140A,
  kWindowsLocaleSpanish_DominicanRepublic= 0x1C0A,
  kWindowsLocaleSpanish_Ecuador          = 0x300A,
  kWindowsLocaleSpanish_ElSalvador       = 0x440A,
  kWindowsLocaleSpanish_Guatemala        = 0x100A,
  kWindowsLocaleSpanish_Honduras         = 0x480A,
  kWindowsLocaleSpanish_Mexico           = 0x080A,
  kWindowsLocaleSpanish_Nicaragua        = 0x4C0A,
  kWindowsLocaleSpanish_Panama           = 0x180A,
  kWindowsLocaleSpanish_Paraguay         = 0x3C0A,
  kWindowsLocaleSpanish_Peru             = 0x280A,
  kWindowsLocaleSpanish_PuertoRico       = 0x500A,
  kWindowsLocaleSpanish_ModernSort       = 0x0C0A,
  kWindowsLocaleSpanish_US               = 0x540A,
  kWindowsLocaleSpanish_Uruguay          = 0x380A,
  kWindowsLocaleSpanish_Venezuela        = 0x200A,
  kWindowsLocaleSweden                   = 0x081D,
  kWindowsLocaleSwedish                  = 0x041D,
  kWindowsLocaleSyriac                   = 0x045A,
  kWindowsLocaleTajik                    = 0x0428,
  kWindowsLocaleTamazight                = 0x085F,
  kWindowsLocaleTamil                    = 0x0449,
  kWindowsLocaleTatar                    = 0x0444,
  kWindowsLocaleTelugu                   = 0x044A,
  kWindowsLocaleThai                     = 0x041E,
  kWindowsLocaleTibetan                  = 0x0451,
  kWindowsLocaleTurkish                  = 0x041F,
  kWindowsLocaleTurkmen                  = 0x0442,
  kWindowsLocaleUighur                   = 0x0480,
  kWindowsLocaleUkrainian                = 0x0422,
  kWindowsLocaleUpperSorbian             = 0x042E,
  kWindowsLocaleUrdu                     = 0x0420,
  kWindowsLocaleUzbek_Cyrillic           = 0x0843,
  kWindowsLocaleUzbek_Latin              = 0x0443,
  kWindowsLocaleVietnamese               = 0x042A,
  kWindowsLocaleWelsh                    = 0x0452,
  kWindowsLocaleWolof                    = 0x0488,
  kWindowsLocaleYakut                    = 0x0485,
  kWindowsLocaleYi                       = 0x0478,
  kWindowsLocaleYoruba                   = 0x046A
};

} // {bl::OpenType::Platform}

//! \}
//! \endcond

#endif // BLEND2D_OPENTYPE_OTPLATFORM_P_H_INCLUDED

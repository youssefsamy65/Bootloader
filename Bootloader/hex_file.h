/*
 * hex_file.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Dell
 */

#ifndef HEX_FILE_H_
#define HEX_FILE_H_
#include "bit_math.h"
#include "std_types.h"
#include "common.h"

const char joe[][50] ={
		 ":020000040800F2Q",
		 ":1040000000000120C5420008CD420008D14200084EQ",
		 ":1040100045430008494300089143000800000000A0Q",
		 ":10402000000000000000000000000000D94300086CQ",
		 ":10403000DD43000800000000E14300085547000888Q",
		 ":10404000F5430008F5430008F5430008F543000870Q",
		 ":10405000F5430008F5430008F5430008254A000829Q",
		 ":104060003D4A0008554A000899470008F5430008F2Q",
		 ":10407000F5430008F5430008F5430008F543000840Q",
		 ":10408000F5430008F5430008F54300080000000070Q",
		 ":104090000000000000000000000000006D4A000861Q",
		 ":1040A000F5430008F5430008F5430008F543000810Q",
		 ":1040B000F5430008F5430008F5430008F543000800Q",
		 ":1040C000F5430008F5430008F5430008F5430008F0Q",
		 ":1040D000F5430008F5430008F54300080000000020Q",
		 ":1040E000C14A0008F5430008F5430008000000003DQ",
		 ":1040F000000000000000000000000000F543000880Q",
		 ":1041000000000000F5430008F5430008F5430008EFQ",
		 ":10411000000000000000000000000000000000009FQ",
		 ":10412000F5430008F5430008F5430008F54300088FQ",
		 ":10413000F54300080000000000000000000000003FQ",
		 ":10414000000000000000000000000000F54300082FQ",
		 ":10415000F5430008F5430008F5430008F54300085FQ",
		 ":10416000F5430008F54300080000000000000000CFQ",
		 ":10417000000000000000000000000000000000003FQ",
		 ":1041800000000000F54300080000000000000000EFQ",
		 ":10419000F543000800B583B000F0BCF9384B394A4CQ",
		 ":1041A0001360394A136039490CE00A684B6801F121Q",
		 ":1041B0000C04886803E011681960043304329842E3Q",
		 ":1041C000F9D82146324B9942EFD32E4B1A68314B26Q",
		 ":1041D0009A4204D12C4B1A682F4B9A4200D0FEE72AQ",
		 ":1041E000274B2E4A13602E4A13602E4B0AE01946C5Q",
		 ":1041F00051F8082B5B6802E00020106004329A42FCQ",
		 ":10420000FAD30B46284A9342F1D3244B1B6813B9C7Q",
		 ":10421000234B1B6803B1FEE700F088F9694601A84BQ",
		 ":1042200000F022F9214C224B1C1BA410002504E0B5Q",
		 ":104230001E4B53F8253098470135AC42F8DC1D4C35Q",
		 ":104240001D4B1C1BA410002504E01A4B53F825300DQ",
		 ":1042500098470135AC42F8DC0099019800F062FA09Q",
		 ":104260000546164C164B1C1BA41004E0013C134BD6Q",
		 ":1042700053F824309847002CF8DC284600F0D0F89AQ",
		 ":10428000BABADECA0000002074000020F84300081BQ",
		 ":104290001044000878563412325476987800002082Q",
		 ":1042A000A801002010440008204400082044000811Q",
		 ":1042B000204400082044000820440008204400084EQ",
		 ":1042C0002044000808B5FFF765FF00BF00BEFEE709Q",
		 ":1042D0001EF0040F0CBFEFF30880EFF30980714666Q",
		 ":1042E000414A10472DE9F04182B004468846134BFDQ",
		 ":1042F0005E6B9F6B9D6A1B6B13F0020F0DD00F4B13Q",
		 ":10430000DB6A002B09DA4BF6AB6100F08BF920B1C8Q",
		 ":104310004FF00042094BDA620CE0094800F0ACF8BBQ",
		 ":10432000CDF800803B4632462946204600F002F98FQ",
		 ":1043300000BEFEE702B0BDE8F08100BF00ED00E086Q",
		 ":104340006455000800BEFEE71EF0040F0CBFEFF33BQ",
		 ":104350000880EFF309807146244A10472DE9F041A7Q",
		 ":1043600082B004468846084B5E6B9F6B9D6A074887Q",
		 ":1043700000F082F8CDF800803B46324629462046C0Q",
		 ":1043800000F0D8F800BEFEE700ED00E0745500082CQ",
		 ":104390001EF0040F0CBFEFF30880EFF309807146A5Q",
		 ":1043A000134A10472DE9F04182B004468846084B75Q",
		 ":1043B0005E6B9F6B9D6A074800F05EF8CDF8008049Q",
		 ":1043C0003B4632462946204600F0B4F800BEFEE7E0Q",
		 ":1043D00000ED00E08055000800BEFEE700BEFEE7EDQ",
		 ":1043E00000BEFEE770470000E54200085D4300089CQ",
		 ":0843F000A543000800BEFEE732Q",
		 ":1043F800D45500080000002078000020D45500089BQ",
		 ":10440800000000100000001078000020AC0100201FQ",
		 ":0844180000000010000000107CQ",
		 ":10442000FEE700BF08B50D4B1B6813B90C4A0B4BD8Q",
		 ":104430001A600A4B1A68C31C23F00303134409498AQ",
		 ":104440008B4206D900F070FB0C2303604FF0FF3065Q",
		 ":1044500008BD02490B60104608BD00BF7C0000206BQ",
		 ":10446000AC01002000FC002001230360014B0B6025Q",
		 ":10447000704700BF040000200FB400B583B004AB48Q",
		 ":1044800053F8042B01938021064800F07FFB00289DQ",
		 ":1044900003DD0146034800F039F803B05DF804EB92Q",
		 ":1044A00004B07047840000202DE9F04385B0044635Q",
		 ":1044B0000F46435613BB042528462146ABBE04468FQ",
		 ":1044C0001FE03546102E28BF1025002306E014F902Q",
		 ":1044D000011B04AA1A4402F8101C0133AB42F6D3A4Q",
		 ":1044E00004AA1344002203F8102CE9464FF00408F4Q",
		 ":1044F00040464946ABBE8046761B00E00E46002E85Q",
		 ":10450000DFD1384605B0BDE8F08300BF08B5FFF73EQ",
		 ":10451000CBFF08BD08B500F095F8024B024A9A603FQ",
		 ":1045200008BD00BF00ED00E00040000808B500F045Q",
		 ":10453000A9F808BDF8B504460D4617461E4626489CQ",
		 ":10454000FFF79AFF21682548FFF796FF6168244826Q",
		 ":10455000FFF792FFA1682348FFF78EFFE16822482AQ",
		 ":10456000FFF78AFF21692148FFF786FF616920482CQ",
		 ":10457000FFF782FFA1691F48FFF77EFFE1691E4830Q",
		 ":10458000FFF77AFF1D48FFF777FF29461C48FFF722Q",
		 ":1045900073FF1C4CE16A1C48FFF76EFF216B1B4840Q",
		 ":1045A000FFF76AFFE16B1A48FFF766FF15F0800F0FQ",
		 ":1045B00003D039461748FFF75FFF15F4004F03D0CBQ",
		 ":1045C00031461548FFF758FF1448FFF755FF069985Q",
		 ":1045D0001348FFF751FFF8BD48540008585400082DQ",
		 ":1045E000685400087854000888540008985400085BQ",
		 ":1045F000A8540008B8540008C8540008D85400084BQ",
		 ":10460000E454000800ED00E0F454000804550008ECQ",
		 ":104610001455000824550008345500084455000876Q",
		 ":104620004C55000883691A888A4207D10268033A08Q",
		 ":10463000012A05D8023383610120704700207047AAQ",
		 ":10464000002070470C4B1A6842F001021A600021EAQ",
		 ":1046500099601A6822F0847222F480321A60074A44Q",
		 ":104660005A601A6822F480221A60D9604FF0006202Q",
		 ":10467000034B9A60704700BF00380240103000249EQ",
		 ":1046800000ED00E0224B9B6803F00C03042B07D0E5Q",
		 ":10469000082B09D0002B2DD11E4A1F4B1A602CE08DQ",
		 ":1046A0001E4A1D4B1A6028E0194B5A685B6803F0DCQ",
		 ":1046B0003F0312F4800F09D0184AB2FBF3F2144BF7Q",
		 ":1046C0005B68C3F3881303FB02F208E0114AB2FBF4Q",
		 ":1046D000F3F30F4A5168C1F3881101FB03F20C4B4DQ",
		 ":1046E0005B68C3F3014301335B00B2FBF3F30A4A97Q",
		 ":1046F000136002E0074A084B1A60054B9B68C3F33EQ",
		 ":104700000313074AD15C044A1368CB401360704717Q",
		 ":10471000003802400024F4000C00002040787D01A5Q",
		 ":104720009055000808B5012000F06CF8012000F059Q",
		 ":104730003DF80021084600F0AFF8012200210846ACQ",
		 ":1047400000F0D0F801220021084600F011F9002005Q",
		 ":1047500008BD00BF08B5024B1B6803B1984708BDF0Q",
		 ":1047600004010020A0F11303DBB2012B0CD91628A1Q",
		 ":104770000CD810B4074C6169012202FA00F343EA35Q",
		 ":1047800001006061104603E0002070470020704780Q",
		 ":1047900010BC7047003C014008B5034B1B699847ABQ",
		 ":1047A0000420FFF7DFFF08BD08010020B0F5803FBFQ",
		 ":1047B0000ED0B0F1807F16D001281FD1104B9A681FQ",
		 ":1047C00022F001029A609A6822F002029A60704711Q",
		 ":1047D0000B4B9A6842F001029A609A6822F002023AQ",
		 ":1047E0009A6001207047064B9A6842F001029A6075Q",
		 ":1047F0009A6842F002029A600120704700207047D8Q",
		 ":1048000000380240012805D0B0F5803F02D0B0F159Q",
		 ":10481000807F3BD11F4A136803431360B0F5803F8CQ",
		 ":1048200014D0B0F1807F21D0012831D11346126815Q",
		 ":1048300022F480321A601A6822F080721A60154BD6Q",
		 ":104840001B6813F0020FFAD001207047114B1A6851Q",
		 ":1048500022F001021A601A6822F080721A600D4B71Q",
		 ":104860001B6813F4003FFAD001207047094B1A6807Q",
		 ":1048700022F001021A601A6822F480321A60054B95Q",
		 ":104880001B6813F0007FFAD00120704700207047AAQ",
		 ":10489000012070470038024003291ED8DFE801F0ECQ",
		 ":1048A000020B11170E490A6B012303FA00F01043A3Q",
		 ":1048B0000863184670470A4A536B18435063012037Q",
		 ":1048C0007047074A136C1843106401207047044A6CQ",
		 ":1048D000536C18435064012070470020704700BF9CQ",
		 ":1048E0000038024010B40F2934D8032A34D80128E4Q",
		 ":1048F00012D010B102281ED030E01A4B1C684900BBQ",
		 ":104900000320884024EA00001860186802FA01F1C8Q",
		 ":1049100001431960012022E0134B1C684900032069Q",
		 ":10492000884024EA00001860186802FA01F1014387Q",
		 ":104930001960012013E00D4B1C68490003208840DAQ",
		 ":1049400024EA00001860186802FA01F101431960B6Q",
		 ":10495000012004E0012002E0012000E0002010BC62Q",
		 ":10496000704700BF000002400004024000080240FFQ",
		 ":1049700030B40F292ED8012A2ED8012810D010B11AQ",
		 ":1049800002281AD02AE0174B5C69012000FA01F5D1Q",
		 ":1049900024EA05045C615C698A4022435A611EE096Q",
		 ":1049A000114B5C69012000FA01F524EA05045C6101Q",
		 ":1049B0005C698A4022435A6111E00C4B5C6901201AQ",
		 ":1049C00000FA01F524EA05045C615C698A4022432FQ",
		 ":1049D0005A6104E0002002E0002000E0012030BC29Q",
		 ":1049E000704700BF0000024000040240000802407FQ",
		 ":1049F000A0F11303012B0CD916280CD810B4084CC5Q",
		 ":104A00006169012202FA00F343EA01006061104685Q",
		 ":104A100003E0002070470020704710BC704700BFC3Q",
		 ":104A2000003C014008B5044B5B681BB1984701206EQ",
		 ":104A3000FFF7DEFF08BD00BF5C01002008B5044B96Q",
		 ":104A40009B681BB198470220FFF7D2FF08BD00BF4BQ",
		 ":104A50005C01002008B5044BDB681BB198470320BCQ",
		 ":104A6000FFF7C6FF08BD00BF5C01002008B5134B6FQ",
		 ":104A70005B691BB198470520FFF7BAFF0F4B9B6995Q",
		 ":104A800023B198470620FFF7B3FF08BD0B4BDB6946Q",
		 ":104A900023B198470720FFF7ABFF08BD074B1B6A00Q",
		 ":104AA00023B198470720FFF7A3FF08BD034B5B6ABCQ",
		 ":104AB0001BB198470720FFF79BFF08BD5C01002052Q",
		 ":104AC00008B5184B9B6A23B198470A20FFF790FF5FQ",
		 ":104AD00008BD144BDB6A23B198470B20FFF788FF12Q",
		 ":104AE00008BD104B1B6B23B198470C20FFF780FFCCQ",
		 ":104AF00008BD0C4B5B6B23B198470D20FFF778FF87Q",
		 ":104B000008BD084B9B6B23B198470E20FFF770FF41Q",
		 ":104B100008BD044BDB6B1BB198470F20FFF768FF04Q",
		 ":104B200008BD00BF5C010020014B1868704700BF42Q",
		 ":104B30007000002030B5141E05469BB0184604DAFCQ",
		 ":104B40008B232B604FF0FF301DE04FF40273ADF864Q",
		 ":104B50000C3014BF04F1FF332346029305934FF644Q",
		 ":104B6000FF7300910491ADF80E3002461E9B69461AQ",
		 ":104B7000284600F073F8431CBCBF8B232B6014B194Q",
		 ":104B8000009B00221A701BB030BD000007B50093D7Q",
		 ":104B900013460A46014603480068FFF7CBFF03B0FFQ",
		 ":104BA0005DF804FB700000202DE9F0478E689E42FEQ",
		 ":104BB00082460C46914698463ED88A8912F4906FF8Q",
		 ":104BC0003AD0256809696F1A6569022305EB450526Q",
		 ":104BD00095FBF3F57B1C43449D4238BF1D465305AEQ",
		 ":104BE0000FD5294600F090FB064698B13A46216958Q",
		 ":104BF00000F016FBA38923F4906343F08003A381A4Q",
		 ":104C000013E02A4600F0DEFB064670B921695046E3Q",
		 ":104C100000F02CFB0C23CAF80030A38943F04003BAQ",
		 ":104C2000A3814FF0FF30BDE8F087266165613E4407Q",
		 ":104C3000ED1B2660A5604646464528BF46463246DFQ",
		 ":104C40004946206800F0F7FAA3689B1BA36023681DQ",
		 ":104C50001E4426600020BDE8F08700002DE9F04FDBQ",
		 ":104C60009DB0804603938B891C060D4616460DD5D4Q",
		 ":104C70000B695BB9402100F047FB2860286118B937Q",
		 ":104C80000C23C8F80030CDE040236B61002309936AQ",
		 ":104C900020238DF82930DFF89CB130238DF82A309DQ",
		 ":104CA00037463C4614F8013B1BB9B7EB060910D058Q",
		 ":104CB00003E0252BF9D02746F3E74B463246294639Q",
		 ":104CC0004046FFF771FF013000F0A780099B4B447DQ",
		 ":104CD00009933B78002B00F0A08000234FF0FF32B7Q",
		 ":104CE00004930793059206938DF853301A93012687Q",
		 ":104CF000052221784E4800F043FA671C049B38B126Q",
		 ":104D00004B4A801A06FA00F0184304903C46EFE73DQ",
		 ":104D1000D90644BF20228DF853201A0744BF2B2206Q",
		 ":104D20008DF8532022782A2A03D0079A00210A20DEQ",
		 ":104D30000BE0039A111D12680391002A10DA524207Q",
		 ":104D400043F00200079204900BE0274601343B78C1Q",
		 ":104D5000303B092B03D800FB02320121F5E701B1FAQ",
		 ":104D600007923B782E2B1ED17B782A2B0AD1039BEEQ",
		 ":104D70001A1D1B680392002BB8BF4FF0FF33023798Q",
		 ":104D8000059310E000230593781C19460A24074672Q",
		 ":104D900001303A78303A092A03D804FB0121012373Q",
		 ":104DA000F5E703B1059103223978224800F0E8F9CCQ",
		 ":104DB00040B14023CBEB000003FA00F0049B184302Q",
		 ":104DC0000490013739781C488DF8281006227E1C83Q",
		 ":104DD00000F0D6F988B1194B33B9039B073323F0A0Q",
		 ":104DE00007030833039314E003AB00932A46144BE4Q",
		 ":104DF00004A94046AFF3008007E003AB00932A46C6Q",
		 ":104E00000F4B04A9404600F093F8B0F1FF3F8246F3Q",
		 ":104E100003D0099B5344099342E7AB895B0601D455Q",
		 ":104E2000099801E04FF0FF301DB0BDE8F08F00BFE2Q",
		 ":104E3000A0550008A6550008AA550008000000006BQ",
		 ":104E4000A94B00082DE9F04791461F460A698B6877Q",
		 ":104E5000DDF820809342B8BF1346C9F8003091F8BEQ",
		 ":104E6000432006460C4612B10133C9F800302368CEQ",
		 ":104E7000990642BFD9F800300233C9F800302568DEQ",
		 ":104E800015F0060510D104F1190A07E00123524676Q",
		 ":104E900039463046C04701301AD00135E368D9F8A9Q",
		 ":104EA00000209B1A9D42F1DB94F8433022680033C6Q",
		 ":104EB00018BF012392060FD5E1185A1C302081F843Q",
		 ":104EC0004300224494F8451082F84310023303E073Q",
		 ":104ED0004FF0FF30BDE8F08704F143023946304619Q",
		 ":104EE000C0470130F4D02268D9F80050E36802F0DEQ",
		 ":104EF0000602042A08BF5D1B2269A3680CBF25EACDQ",
		 ":104F0000E57500259342C4BF9B1AED184FF00009C8Q",
		 ":104F10001A344D4509D00123224639463046C04750Q",
		 ":104F20000130D5D009F10109F3E70020BDE8F08791Q",
		 ":104F30002DE9F04317460A7E85B06E2A984606464CQ",
		 ":104F40000C460C9B01F1430E00F0AE8011D8632A91Q",
		 ":104F500022D009D8002A00F0BB80582A40F0CA802DQ",
		 ":104F600081F84520834955E0642A1ED0692A1CD067Q",
		 ":104F7000C0E0732A00F0B08009D86F2A2ED0702AC2Q",
		 ":104F800040F0B8800A6842F020020A603EE0752ACCQ",
		 ":104F900024D0782A3AD0ADE01A6801F14205111DFBQ",
		 ":104FA0001960136884F84230A8E021681A6811F08BQ",
		 ":104FB000800F02D0111D196008E011F0400F02F1BEQ",
		 ":104FC0000401196002D0B2F9003000E01368002B30Q",
		 ":104FD0003CDA2D225B4284F8432037E021681A68CEQ",
		 ":104FE00011F0800F02D0111D196007E011F0400F81Q",
		 ":104FF00002F10401196001D0138800E01368227ED9Q",
		 ":105000005C496F2A14BF0A2208221BE078225A4901Q",
		 ":1050100084F845202268186812F0800F00F104051AQ",
		 ":105020001D6003D1550601D5038800E00368D00751Q",
		 ":1050300044BF42F0200222601BB9226822F0200205Q",
		 ":1050400022601022002084F8430001E049490A222EQ",
		 ":105050006568A560002D08DB206820F00400206052Q",
		 ":105060002BB9002D7DD175460CE0002B79D075460BQ",
		 ":10507000B3FBF2F002FB1033CB5C05F8013D0346B5Q",
		 ":105080000028F5D1082A0BD12368DA0708D523694FQ",
		 ":1050900062689A42DEBF302305F8013C05F1FF3516Q",
		 ":1050A000C5EB0E0323612EE008681A68496910F009Q",
		 ":1050B000800F03D0101D1860136808E010F0400F37Q",
		 ":1050C00002F104001860136801D0198000E0196033Q",
		 ":1050D00000232361754616E01A68111D19601568D2Q",
		 ":1050E00062680021284600F04BF808B1401B606060Q",
		 ":1050F000636804E004F1420584F84220012323613FQ",
		 ":10510000002384F84330CDF800803B4603AA2146B3Q",
		 ":105110003046FFF797FE013002D14FF0FF3026E016Q",
		 ":1051200023692A4639463046C0470130F5D0236806Q",
		 ":105130009B0710D5002504F1190907E001234A4611Q",
		 ":1051400039463046C0470130E7D00135E368039A5DQ",
		 ":105150009B1A9D42F2DBE068039B9842B8BF184659Q",
		 ":1051600005E00B7884F8423004F142058AE705B087Q",
		 ":10517000BDE8F083B1550008C255000800000000EAQ",
		 ":1051800001F0FF01102A2BDB10F0070F08D010F8F8Q",
		 ":10519000013B013A8B422DD010F0070F42B3F6D1FCQ",
		 ":1051A000F0B441EA012141EA014122F007047FF015Q",
		 ":1051B00000070023F0E80256083C85EA010586EA6CQ",
		 ":1051C000010685FA47F5A3FA87F586FA47F6A5FAA8Q",
		 ":1051D00087F68EB9EED1F0BC01F0FF0102F00702B4Q",
		 ":1051E00032B110F8013B013A83EA010313B1F8D15FQ",
		 ":1051F0000020704701387047002D06BF3546033840Q",
		 ":10520000073815F0010F07D1013015F4807F02BF78Q",
		 ":10521000013015F4C03F0130F0BC0138704700BFC9Q",
		 ":1052200010B5431E0A44914204D011F8014B03F813Q",
		 ":10523000014FF8E710BD884210B501EB020301D819Q",
		 ":10524000421E0BE09842FBD28118D21AD34204D0FEQ",
		 ":1052500013F8014D01F8014DF8E710BD994204D053Q",
		 ":1052600011F8014B02F8014FF8E710BD38B50546BBQ",
		 ":10527000002946D051F8043C0C1F002BB8BFE4189DQ",
		 ":1052800000F0D6F81F4A1368114613B96360146022Q",
		 ":1052900032E0A3420ED92268A018834204BF1868E6Q",
		 ":1052A0005B68636004BF121822600C6024E0A242B5Q",
		 ":1052B00003D813465A68002AF9D118681918A14270Q",
		 ":1052C0000BD12168014458188242196014D110682AQ",
		 ":1052D00052685A60014419600EE002D90C232B6019Q",
		 ":1052E0000AE021686018824204BF10685268626058Q",
		 ":1052F00004BF091821605C602846BDE8384000F012Q",
		 ":1053000098B838BDA001002070B5CD1C25F003056CQ",
		 ":1053100008350C2D38BF0C25002D064601DBA942AFQ",
		 ":1053200002D90C23336046E000F082F8234B1C685EQ",
		 ":105330001A462146A1B10B685B1B0ED40B2B03D977Q",
		 ":105340000B60CC18CD501EE08C420DBF63684B68DBQ",
		 ":105350006360136018BF0C4615E00C464968E9E726Q",
		 ":10536000174C23681BB9304600F052F820602946DCQ",
		 ":10537000304600F04DF8431C18D0C41C24F0030440Q",
		 ":10538000A0420DD12560304600F053F804F10B0027Q",
		 ":10539000231D20F00700C31A0ED05A42E25070BD00Q",
		 ":1053A000211A304600F034F80130EBD10C23336081Q",
		 ":1053B000304600F03EF8002070BD00BFA001002084Q",
		 ":1053C0009C010020F8B5074615460E4621B9114646Q",
		 ":1053D000BDE8F840FFF798BF1AB9FFF747FF284626Q",
		 ":1053E000F8BD00F027F885420ED929463846FFF768Q",
		 ":1053F0008BFF044650B131462A46FFF711FF314674Q",
		 ":105400003846FFF733FF01E03046F8BD2046F8BDCFQ",
		 ":1054100038B5064C0023054608462360FFF702F81EQ",
		 ":10542000431C02D1236803B12B6038BDA4010020C6Q",
		 ":105430007047704751F8040C0028BEBF091851F896Q",
		 ":10544000043CC01804387047537461636B20667263Q",
		 ":10545000616D653A0A000000205230203D20202571Q",
		 ":105460003038580A00000000205231203D2020250DQ",
		 ":105470003038580A00000000205232203D202025FCQ",
		 ":105480003038580A00000000205233203D202025EBQ",
		 ":105490003038580A0000000020523132203D2025CBQ",
		 ":1054A0003038580A00000000204C52203D202025B2Q",
		 ":1054B0003038580A00000000205043203D202025ADQ",
		 ":1054C0003038580A0000000020505352203D20255BQ",
		 ":1054D0003038580A000000004653522F4641523AD5Q",
		 ":1054E0000A0000002043465352203D20202530383AQ",
		 ":1054F000580A00002048465352203D2020253038CDQ",
		 ":10550000580A00002044465352203D2020253038C0Q",
		 ":10551000580A00002041465352203D2020253038B3Q",
		 ":10552000580A0000204D4D464152203D202530387CQ",
		 ":10553000580A00002042464152203D2020253038A4Q",
		 ":10554000580A00004D6973630A000000204C522F76Q",
		 ":105550004558435F52455455524E3D2025303858EAQ",
		 ":105560000A0000005B486172644661756C745D0AF4Q",
		 ":10557000000000005B4275734661756C745D0A0043Q",
		 ":105580005B55736167654661756C745D0A00000068Q",
		 ":1055900000000000000000000102030406070809E3Q",
		 ":1055A000232D302B2000686C4C006566674546470CQ",
		 ":1055B000003031323334353637383941424344458FQ",
		 ":1055C00046003031323334353637383961626364FEQ",
		 ":0355D0006566000DQ",
		 ":1055D4007856341280000020000000000024F400FBQ",
		 ":1055E40000000000000000000000000000000000B7Q",
		 ":1055F40000000000000000000000000000000000A7Q",
		 ":105604000000000000000000000000000000000096Q",
		 ":105614000000000000000000000000000000000086Q",
		 ":105624000000000000000000000000000000000076Q",
		 ":105634000000000000000000000000000000000066Q",
		 ":0856440010000020325476989AQ",
		 ":040000050800419519Q",
		 ":00000001FFQ",

};



#endif /* HEX_FILE_H_ */
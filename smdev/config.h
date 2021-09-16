/* See LICENSE file for copyright and license details. */
struct rule {
	const char *devregex;
	const char *user;
	const char *group;
	int mode;
	const char *path;
	const char *cmd;
} rules[] = {
	//tty
	{ "console",       "root", "tty",   0600, NULL,      NULL                           },
	{ "pty.*",         "root", "tty",   0660, NULL,      NULL                           },
	{ "ptmx",          "root", "tty",   0666, NULL,      NULL                           },
	{ "tty",           "root", "tty",   0666, NULL,      NULL                           },
	{ "tty[0-9]",      "root", "tty",   0600, NULL,      NULL                           },
	{ "tty[0-9][0-9]", "root", "tty",   0660, NULL,      NULL                           },
	{ "vcs*[0-9].*",    "root", "tty",   0660, NULL,      NULL                           },
	// serial
	{ "tty.*",         "root", "uucp",  0660, NULL,      NULL                           },
	{ "slamr",         "root", "tty",   0660, NULL,      NULL                           },
	{ "slusb",         "root", "tty",   0660, NULL,      NULL                           },
	{ "vport.*",       "root", "root",  0660, NULL,      NULL                           },
	{ "ircomm[0-9].*", "root", "uucp",  0660, NULL,      NULL                           },
	{ "noz[0-9].*",    "root", "uucp",  0660, NULL,      NULL                           },
	{ "rfcomm[0-9].*", "root", "uucp",  0660, NULL,      NULL                           },
	{ "mwave",         "root", "uucp",  0660, NULL,      NULL                           },
	{ "hvc.*",         "root", "uucp",  0660, NULL,      NULL                           },
	{ "hvi.*",         "root", "uucp",  0660, NULL,      NULL                           },
	{ "ppox[0-9].*",   "root", "uucp",  0660, NULL,      NULL                           },
	// mem
	{ "null",          "root", "root",  0666, NULL,      NULL                           },
	{ "zero",          "root", "root",  0666, NULL,      NULL                           },
	{ "full",          "root", "root",  0666, NULL,      NULL                           },
	{ "random",        "root", "root",  0666, NULL,      "@/etc/processdev/processdev"        },
	{ "urandom",       "root", "root",  0444, NULL,      "@/etc/processdev/processdev"        },
	{ "hwrandom",      "root", "root",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "hw_random",     "root", "root",  0660, "=hwrng",  "@/etc/processdev/processdev"        },
	{ "mem",           "root", "kmem",  0640, NULL,      "@/etc/processdev/processdev"        },
	{ "kmem",          "root", "kmem",  0640, NULL,      "@/etc/processdev/processdev"        },
	{ "port",          "root", "kmem",  0640, NULL,      "@/etc/processdev/processdev"        },
	{ "nvram",         "root", "kmem",  0640, NULL,      "@/etc/processdev/processdev"        },
	// input
	{ "input/.*",      "root", "input", 0660, "=input/", "@/etc/processdev/processdev"        },
	{ "ts[0-9].+",     "root", "root",  0640, "=input/", "@/etc/processdev/processdev"        },
	// graphics
	{ "video.*",       "root", "video", 0660, NULL,      "@/etc/processdev/processdev"        },
	{ "vchiq",         "root", "video", 0660, NULL,      "@/etc/processdev/processdev"        },
	{ "vbi[0-9]",      "root", "video", 0660, NULL,      "@/etc/processdev/processdev"        },
	{ "cec[0-9]",      "root", "video", 0660, NULL,      "@/etc/processdev/processdev"        },
	{ "agpgart",       "root", "video", 0660, NULL,      "@/etc/processdev/processdev"        },
	{ "pmu",           "root", "video", 0660, NULL,      "@/etc/processdev/processdev"        },
	{ "fb[0-9].*",     "root", "video", 0660, NULL,      "@/etc/processdev/processdev"        },
	{ "nvidia",        "root", "video", 0660, NULL,      "@/etc/processdev/processdev"        },
	{ "nvidiactl",     "root", "video", 0660, NULL,      "@/etc/processdev/processdev"        },
	// dri
	{ "dri/.*",        "root", "video", 0660, "=dri/",   "@/etc/processdev/processdev"        },
	{ "card[0-9].*",   "root", "video", 0660, "=dri/",   "@/etc/processdev/processdev"        },
	// usb
	{ "bus/usb/.*",    "root",  "usb",   0664, NULL,      "@/etc/processdev/processdev"        },
	// printer
	{ "partport[0-9].*","root", "lp",    0660, NULL,      "@/etc/processdev/processdev"        },
	{ "partport_pc",    "root", "lp",    0660, NULL,      "@/etc/processdev/processdev"        },
	{ "usb/lp[0-9].*",  "root", "lp",    0660, "=usb/",   "@/etc/processdev/processdev"        },
	{ "lp[0-9]*",       "root", "lp",    0660, NULL,      "@/etc/processdev/processdev"        },
	{ "irlpt[0-9].*",   "root"," lp",    0660, NULL,      "@/etc/processdev/processdev"        },
	// block
	{ "sd[a-z].*",      "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "hd[a-z].*",      "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "ram[0-9].*",     "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "loop[0-9].*",    "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "control",        "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "mmcblk[0-9].*",  "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "md.*",           "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "mtd.*",          "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "ndb.*",          "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "gnbd.*",         "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "btibm.*",        "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "dm-.*",          "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "vd.*",           "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "sg.*",           "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "sr[0-9].*",      "root", "cdrom", 0660, NULL,      "@/etc/processdev/processdev"        },//"@ln -sf $DEVNAME /dev/cdrom"
	{ "fd[0-9].*",      "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	// tape
	{ "ht[0-9].*",      "root", "tape",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "nht[0-9].*",     "root", "tape",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "pt[0-9].*",      "root", "tape",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "npt[0-9].*",     "root", "tape",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "pht[0-9].*",     "root", "tape",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "st*[0-9].*",     "root", "tape",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "nst*[0-9].*",    "root", "tape",  0660, NULL,      "@/etc/processdev/processdev"        },
	//block-related
	{ "btrfs-control",  "root", "root",  0600, NULL,      "@/etc/processdev/processdev"        },
	{ "loop-control",   "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "mapper/.*",      "root", "root",  0600, "=mapper/","@/etc/processdev/processdev"        },
	{ "scsi.*/.*",      "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "bdi.*/.*",       "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "sch[0-9].*",     "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "pg[0-9].*",      "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "qft[0-9].*",     "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "nqft[0-9].*",    "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "zqft[0-9].*",    "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "nzqft[0-9].*",   "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "rawqft[0-9].*",  "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "nrawqft[0-9].*", "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "raw[0-9].*",     "root", "disk",  0660, "=raw/",   "@/etc/processdev/processdev"        },
	{ "rawctl",         "root", "disk",  0660, "=raw/",   "@/etc/processdev/processdev"        },
	{ "aoe.*",          "root", "disk",  0660, "=etherd/","@/etc/processdev/processdev"        },
	{ "bsg/.*",         "root", "disk",  0660, "=bsg/",   "@/etc/processdev/processdev"        },
	// audio
	{ "snd/.*",         "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "midi.*",         "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "seq",            "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "timer",          "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "hpet",           "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "adsp",           "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "audio",          "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "dsp",            "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "mixer",          "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "sequencer.*",    "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "timer",          "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	{ "pcm.*",          "root", "audio", 0660, "=snd/",   "@/etc/processdev/processdev"        },
	// network
	{ "-net/.*",        "root", "network",  0660, NULL,      "@nameif"                      },
	{ "tun",            "root", "network",  0666, "=net/",   "@/etc/processdev/processdev"        },
	{ "tun[0-9].*",     "root", "network",  0660, "=net/",   "@/etc/processdev/processdev"        },
	{ "tap[0-9].*",     "root", "network",  0660, "=net/",   "@/etc/processdev/processdev"        },
	{ "rfkill",         "root", "rfkill",   0640, NULL,      "@/etc/processdev/processdev"        },
	// cpu
	{ "cpu([0-9].+)",   "root", "root",  0444, "=cpu/%1/cpuid", "@/etc/processdev/processdev"        },
	{ "msr([0-9].+)",   "root", "root",  0600, "=cpu/%1/msr",   "@/etc/processdev/processdev"        },
	{ "microcode",      "root", "root",  0600, "=cpu/microcode","@/etc/processdev/processdev"        },
	// fuse
	{ "fuse",           "root", "root",  0666, NULL,      "@mount -t fusectl fusectl /sys/fs/fuse/connections"},
	// raid controllers
	{ "cciss.*",        "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "ida.*",          "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "rd.*",           "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	// misc
	{ "ppp",            "root", "root",  0000, NULL,      "@/etc/processdev/processdev"        },
	{ "kvm",            "root", "kvm",   0660, NULL,      "@/etc/processdev/processdev"        },
	{ "vhost-net",      "root", "kvm",   0666, NULL,      "@/etc/processdev/processdev"        },
	{ "vhost-vsock",    "root", "kvm",   0666, NULL,      "@/etc/processdev/processdev"        },
	{ "rtc",            "root", "root",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "rtc[0-9]*",      "root", "root",  0664, NULL,      "@/etc/processdev/processdev"        },
	{ "mmtimer",        "root", "root",  0644, NULL,      "@/etc/processdev/processdev"        },
	{ "rflash[0-9]*",   "root", "root",  0400, NULL,      "@/etc/processdev/processdev"        },
	{ "rrom[0-9]*",     "root", "root",  0400, NULL,      "@/etc/processdev/processdev"        },
	{ "auer[0-9]*",     "root", "root",  0660, "=usb/",   "@/etc/processdev/processdev"        },
	{ "sxctl",          "root", "root",  0660, "=specialix_sxctl/",   "@/etc/processdev/processdev"        },
	{ "rioctl",         "root", "root",  0660, "=specialix_rioctl/",  "@/etc/processdev/processdev"        },
	//arch
	{ "sgi_.*",         "root", "root",  0666, NULL,      "@/etc/processdev/processdev"        },
	{ "iseries/ibmsis.*","root","disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "iseries/nvt.*",  "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "iseries/vt.*",   "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	{ "iseries/vtty.*", "root", "disk",  0660, NULL,      "@/etc/processdev/processdev"        },
	
	{ ".*",             "root", "root",  0660, NULL,      "@/etc/processdev/processdev"        },
};

/* Fill into this table if you want to rename the network interface
 * identified by `mac' to `name'.  By default no such renaming takes
 * place.
 */
struct mac2name {
	unsigned char mac[6];
	const char *name;
} mac2names[] = {
	{ .mac = { 0 }, .name = NULL }
};

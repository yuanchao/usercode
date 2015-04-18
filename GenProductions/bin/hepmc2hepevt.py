#
# Yuan CHAO     20015/04/09

import sys, os, string

class HepVertex:
    ''' A class to hold the generator vertices '''
    def __init__(self):
        self.idx = 0
        self.v4 = (0.0, 0.0, 0.0)
        self.mother = []
        self.daughter = []
        self.n_in = 0
        self.n_out = 0

    def parse(self, str_in):
        if str_in.find("V ") == 0:
            entries = str_in.split()
            self.idx = int(entries[1])
            self.v4 = (float(entries[3]), # vx, vy, vz, ct
                       float(entries[4]),
                       float(entries[5]),
                       float(entries[6]))
            self.n_in = int(entries[7])
            self.n_out = int(entries[8])

        else:
            print "Parsing error!!!"

    def add_mo(self, mo_idx):
        self.mother.append(mo_idx)

    def add_da(self, da_idx):
        self.daughter.append(da_idx)

    def __str__(self):
        m_str = "{:5d} {:5d} {:5d}".format(self.idx,
                                           self.n_in,
                                           self.n_out)

        m_str = m_str + " {:10s} {:10s}".format(str(self.mother),
                                                str(self.daughter))

#        for i in self.v4 :
#            m_str = m_str + " {:15e}".format(i)

        return m_str

class HepParticle:
    ''' A class to hold the generator particles '''
    def __init__(self):
        self.idx = 0
        self.p4 = (0.0, 0.0, 0.0, 0.0) # px, py, pz, E
        self.v4 = (0.0, 0.0, 0.0, 0.0) # vx, vy, vz, ct
        self.mass = 0.0
        self.mother = []
        self.daughter = []
        self.mo = []
        self.da = []
        self.status = 0
        self.pdgid = 0
        self.vid = 0
        self.order = 0

    def parse(self, str_in):
        if str_in.find("P ") == 0:
            entries = str_in.split()
            #print entries

            if len(entries) == 14 :
                entries = str_in.replace("	","").split()
            
            self.idx = int(entries[1])
            self.pdgid = int(entries[2])

            self.p4 = (float(entries[3]),
                       float(entries[4]),
                       float(entries[5]),
                       float(entries[6]))
            self.mass = float(entries[7])
            self.status = int(entries[8])
            self.vid = int(entries[11])

        else:
            print "Parsing error!!!"

    def add_mo(self, mo_idx):
        self.mother.append(mo_idx)

    def add_da(self, da_idx):
        self.daughter.append(da_idx)

    def __str__(self):
#        m_str = "{:5d} {:5d} {:5d} {:5d} {:5d} {:5d}".format(self.status,
#                                                             self.pdgid,
#                                                             0, 0, 0, 0)
#        m_str = "{:5d} {:5d} {:5d} {:5d} {:10s} {:10s}".format(self.order,
#                                                               self.idx,
#                                                               self.status,
#                                                               self.pdgid,
#                                                               str(self.mo),
#                                                               str(self.da))
#        m_str = "{:5d} {:5d} {:5d} {:5d} {:5d} {:5d} {:5d}".format(self.order,
        m_str = "{:5d} {:5d} {:5d} {:5d} {:5d} {:5d}".format(self.status,
                                                             self.pdgid,
                                                             self.mo[0],
                                                             self.mo[-1],
                                                             self.da[0],
                                                             self.da[-1])
        for i in self.p4 :
            m_str = m_str + " {:15e}".format(i)

        m_str = m_str + " {:15e}".format(self.mass)

        for i in self.v4 :
            m_str = m_str + " {:15e}".format(i)

        return m_str

#    def __repr__(self):
#        return "{:5d} {:9d} {:5d} {:5d} {:5d} {:5d} {:16g} {:16g} {:16g} {:16g} {:16g} {:16g} {:16g} {:16g}".format(self.status, self.idx, self.mo, self.da, self.p4, self.v4)

# -----------------------------------------------------------------------------

if __name__ == "__main__":

    # If no arguments were given, print a helpful message
    if len(sys.argv)<3:
        print 'Usage: '+sys.argv[0]+' in_name out_name'
        sys.exit(0)

    f_in = open(sys.argv[1], 'r')
    f_out = open(sys.argv[2], 'w')

    particle_list = []
    vertex_list = []
    particle_dict = {}
    #particle_order = {}
    vertex_dict = {}

    last_vtx = HepVertex
    last_ptl = HepParticle

    last_mo_idx = 0
    last_da_idx = 0

    last_mo_ptl = HepParticle

    n_events = 0

    f_in.readline()

    if f_in.readline()[0:7] != "HepMC::" :
        print "HepMC header error!"
        sys.exit(-1)

    if f_in.readline()[0:7] != "HepMC::" :
        print "HepMC header error!"
        sys.exit(-1)

    while (1):
        in_line = f_in.readline()
        #if in_line == "": break

        if in_line[0:2] == 'E ' or (n_events > 0 and in_line == "") :
            ''' a new event '''
            #print len(particle_list), len(vertex_dict)
            if n_events > 0 : f_out.write(str(len(particle_list))+'\n')

            n_events += 1

            if len(particle_list) > 0 and len(vertex_list) > 0 :
                ''' print out the event '''

            #if n_events > 0 :
                p_list = particle_list[:]
                for ip in p_list :
                    if ip.vid < 0 and len(vertex_dict[ip.vid].daughter) > 0:
                        if len(vertex_dict[ip.vid].daughter) >= 1:
                            ip.add_da(vertex_dict[ip.vid].daughter[0])
                        if len(vertex_dict[ip.vid].daughter) >= 2:
                            ip.add_da(vertex_dict[ip.vid].daughter[-1])

                        if len(vertex_dict[ip.vid].mother) <= 1 and \
                           not ip.idx in vertex_dict[ip.vid].mother :
                            vertex_dict[ip.vid].add_mo(ip.idx)
                    for vtx in vertex_list :
                        if len(ip.mother) == 0 and (ip.idx in vtx.daughter) :
                            if len(vtx.mother) >= 1:
                                ip.add_mo(vtx.mother[0])
                            if len(vtx.mother) >= 2:
                                ip.add_mo(vtx.mother[1])

                    # re-enter order id
                    if len(ip.mother) < 1 : ip.mo = [0]
                    else : ip.mo = [ particle_dict[ip.mother[0]].order ]
                    if len(ip.mother) < 2 : ip.mo.append(0)
                    else : ip.mo.append(particle_dict[ip.mother[-1]].order)

                    if len(ip.daughter) < 1 : ip.da = [0]
                    else : ip.da = [ particle_dict[ip.daughter[0]].order ]
                    if len(ip.daughter) < 2 : ip.da.append(0)
                    else : ip.da.append(particle_dict[ip.daughter[-1]].order)

                    f_out.write(str(ip)+'\n')

                #print
                #
                #v_list = vertex_list[:]
                #for iv in v_list :
                #    print iv


            particle_list[:] = []
            vertex_list[:] = []
            particle_dict.clear()
            vertex_dict.clear()

            if in_line == "": 
                print '\nTotal '+str(n_events)+' processed.'
                break

        if in_line[0:2] == 'V ':
            m_vtx = HepVertex()
            m_vtx.parse(in_line)
            vertex_list.append(m_vtx)
            vertex_dict[m_vtx.idx] = m_vtx
            last_vtx = m_vtx

            # go through vertex daughter particles
            for idx in range(0, last_vtx.n_in) :
                in_line = f_in.readline()
                if in_line[0:2] == 'P ':
                    #print " a particle"
                    m_ptl = HepParticle()
                    m_ptl.parse(in_line)
                    m_ptl.v4 = m_vtx.v4
                    m_ptl.order = len(particle_list)+1
                    particle_list.append(m_ptl)
                    particle_dict[m_ptl.idx] = m_ptl
                    #last_ptl = len(particle_list)
                    last_vtx.add_mo(m_ptl.idx)
            
            for idx in range(0, last_vtx.n_out) :
                in_line = f_in.readline()
                if in_line[0:2] == 'P ':
                    m_ptl = HepParticle()
                    m_ptl.parse(in_line)
                    m_ptl.v4 = m_vtx.v4
                    m_ptl.order = len(particle_list)+1
                    particle_list.append(m_ptl)
                    particle_dict[m_ptl.idx] = m_ptl

                    last_vtx.add_da(m_ptl.idx)
                        
    f_out.write('')

